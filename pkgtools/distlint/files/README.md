$NetBSD: README.md,v 1.1 2022/08/20 13:32:06 rillig Exp $

# Introduction

Distlint ensures that the distfiles on the TNF servers conform to the
license requirements.

Distfiles distributed under the GPL must be kept available for as long
as a binary package based on this distfile is distributed, plus 3
years.<sup>[citation needed]</sup>

Distfiles from packages with `NO_SRC_ON_FTP` must not be available at all.

Edge case: Imagine a package having `NO_SRC_ON_FTP` and multiple distfiles.
Some of them must not be available, the others have license GPL.

# Configuration

Distlint is configured by the `distlint.conf` file, which contains one
or more distdir sections. Each such section configures how a single
distdir is related to the directories for pkgsrc installations and
binary package directories:

~~~text
# Each distdir can be populated by several pkgsrc versions, such as 
# pkgsrc-current and the quarterly branches.
# Each distdir can be the source for multiple distributions of binary
# packages, for example for different platforms. 

distdir /usr/pkgsrc/distfiles
        database /var/db/distlint/main 
        pkgsrc /usr/pkgsrc-current
        pkgsrc /usr/pkgsrc-2022Q2
        pkgsrc /usr/pkgsrc-2022Q1
        packages /usr/pkgsrc/packages
        packages /usr/pkgsrc/current-packages

distdir /pub/pkgsrc-archive/distfiles
        database /var/db/distlint/archive                
        pkgsrc /pub/pkgsrc-archive/pkgsrc
        packages /pub/pkgsrc-archive/packages       
~~~

# Infrastructure overview

* https://cdn.netbsd.org/pub/pkgsrc/distfiles/
* https://cdn.netbsd.org/pub/pkgsrc/packages/
* https://archive.netbsd.org/pub/pkgsrc-archive/distfiles/
* https://archive.netbsd.org/pub/pkgsrc-archive/packages/

# Approach

Distlint maintains a database of distfile requirements.
The requirements are collected from all pkgsrc branches that are either
current or in the archive.

## Examples of database entries

_$distfile_ must not be in distfiles, because on _$updated_at_,
it belonged to package _$pkgname_ in _$pkgpath_,
which was marked as `NO_SRC_ON_FTP` because _$no_src_on_ftp_.

_$distfile_ must be kept in distfiles until _$keep_until_,
because on _$updated_at_, it belonged to package _$pkgname_,
which is published at _$publish_url_ and licensed under _$license_.

# Implementation details

## NO_SRC_ON_FTP

To find out whether a binary package has `NO_SRC_ON_FTP`, look at its
`+BUILD_INFO`.

## Find out the distfiles of a binary package

For most binary packages, the file `+BUILD_VERSION` contains the CVS
revision information of the `distinfo` file.

Some packages use `DISTINFO_FILE` to refer to a `distinfo` file outside
their PKGPATH. The CVS revision information for these `distinfo` files is
not recorded anywhere.

Some packages have no `distinfo` file at all because they are self-contained.
Example: pkgtools/lintpkgsrc.

Whether a binary package had a `distinfo` file or not is not visible from
looking at the binary package alone.

Using the CVS revision information of the `distinfo` file,
its file list can be retrieved from CVS.

# Quick hacks

## Find distfiles with NO_SRC_ON_FTP

This program finds most distfiles with NO_SRC_ON_FTP that are referenced
from the current pkgsrc tree.

Shortcomings:

* It does not find distfiles from stable pkgsrc branches.
* It does not find distfiles from previous versions of the packages.
* It does not find distfiles from packages with `DISTINFO_FILE`.

~~~shell
ssh ftp.netbsd.org
cd /pub/pkgsrc/current/pkgsrc

for pkgpath in $(grep -r NO_SRC_ON_FTP . 2>/dev/null | cut -d/ -f2-3); do

  if [ -f "$pkgpath/distinfo" ] &&
    ! grep -r MASTER_SITE_LOCAL "$pkgpath" >/dev/null 2>&1; then

    sed -n 's,^Size (\(.*\)) =.*$,\1,p' "$pkgpath/distinfo" |
      while read distfile; do
        if [ -f "/pub/pkgsrc/distfiles/$distfile" ]; then
          echo "$distfile"
        fi
      done
  fi
done | sort
~~~
