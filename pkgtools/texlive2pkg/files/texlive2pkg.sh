#!/bin/sh
# texlive2pkg
# $NetBSD: texlive2pkg.sh,v 1.4 2022/08/19 18:31:23 wiz Exp $
#
# Copyright (c) 2016
#       Mark Davies.  All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
# 3. Neither the name of the author nor the names of any contributors
#    may be used to endorse or promote products derived from this software
#    without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
# OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
# OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
# SUCH DAMAGE.
#
#
# Create a texlive package in the current directory

NAME=texlive2pkg
TDIR=/tmp/tl.$$
DISTDIR=@DISTDIR@
LIBEXECDIR=@PREFIX@/libexec/texlive2pkg
MAKE=@MAKE@
FTP=@FTP@
pkgtarball=""
doctarball=""
dodoc=0
pkgurl=0
docurl=0

usage="${NAME} [-d] package-tarball [doc-tarball] -- create a texlive package for pkgsrc"

if [ "$1" = "-d" ]; then
  dodoc=1
  shift
fi

if [ ${#} -eq 1 ]; then
  pkgtarball=$1
  if [ $dodoc -eq 1 ]; then
    doctarball=${pkgtarball%%.tar.xz}.doc.tar.xz
  fi
elif [ ${#} -eq 2 ]; then
  pkgtarball=$1
  doctarball=$2
else
  echo "${usage}" 1>&2
  exit 1
fi

case $pkgtarball in
file:/*.tar.xz | ftp:/*.tar.xz | http:/*.tar.xz | https:/*.tar.xz )
   pkgurl=1
    ;;
/*.tar.xz)
    ;;
*.tar.xz)
   pkgtarball=$PWD/$pkgtarball
    ;;
*)
   echo "${usage}" 1>&2
   exit 1
esac

case "$doctarball" in
"")
    ;;
file:/*.doc*.tar.xz | ftp:/*.doc*.tar.xz | http:/*.doc*.tar.xz | https:/*.doc*.tar.xz )
   docurl=1
    ;;
/*.doc*.tar.xz)
    ;;  
*.doc*.tar.xz)
   doctarball=$PWD/$doctarball
    ;;
*)
   echo "${usage}" 1>&2
   exit 1
esac

mkdir $TDIR

if [ $pkgurl -eq 1 ]; then
  (cd $TDIR; $FTP $pkgtarball )
  pkgtarball=$TDIR/`basename $pkgtarball`
fi
if [ $docurl -eq 1 ]; then
  (cd $TDIR; $FTP $doctarball )
  doctarball=$TDIR/`basename $doctarball`
fi

if [ ! -f $pkgtarball ]; then
  echo "File not found - $pkgtarball"
  exit 1
fi

(cd $TDIR ; xzcat $pkgtarball | tar xf - tlpkg)
eval `$LIBEXECDIR/texlive.pkg $TDIR/tlpkg/tlpobj/*.tlpobj`
mkdir -p $DISTDIR/tex-$PKG-$REV
cp $pkgtarball $doctarball $DISTDIR/tex-$PKG-$REV/
(cd tex-$PKG; $MAKE makesum)
if [ -f "$doctarball" ]; then
   (cd $TDIR; xzcat $doctarball | tar xf - tlpkg)
   $LIBEXECDIR/texlive.pkg.doc $PKG $REV "$VERSION" "$LICENSE" "$HOMEPAGE" < $TDIR/tlpkg/tlpobj/${PKG}.doc.tlpobj && \
   (cd tex-$PKG-doc; $MAKE makesum)
fi
rm -rf $TDIR
