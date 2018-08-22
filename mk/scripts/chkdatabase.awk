#!/usr/bin/awk -f
#
# $NetBSD: chkdatabase.awk,v 1.4 2018/08/22 20:48:37 maya Exp $
#
# Copyright (c) 2002, 2003 The NetBSD Foundation, Inc.
# All rights reserved.
#
# This code is derived from software contributed to The NetBSD Foundation
# by Dan McMahill.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
# ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
# TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
# BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#

# This script reads a pkgsrc database created with the 'print-summary-data'
# target and returns a lists of packages which are listed as DEPENDS and/or
# BUILD_DEPENDS but do not have their own dependencies recorded yet.
# This can be used as part of a loop which makes several passes to record
# the complete dependency tree for a package in the database
#

BEGIN {
  if(debug) {
    printf("Reading database file\n") > "/dev/stderr";
    fflush("/dev/stderr");
  }
}

/^(build_)?depends / {
#
# Read in the entire depends tree
# These lines look like:
#
#depends /usr/pkgsrc/math/scilab xless-[0-9]*:../../x11/xless pvm-3.4.3:../../parallel/pvm3
#build_depends /usr/pkgsrc/math/scilab libtool-base>=1.4.20010614nb9:../../devel/libtool-base
#
  pkg = $2;

# mark this package as having its depencencies listed
  depended_pkgs[pkg] = 1;

# now go through the dependency lists and pull out all pkg directories that
# we will need to examine to ensure they have been depended.
  for(i=3; i<=NF; i++) {
    split($i,a,":");
    pkgpat=a[1];
    pkgdir=a[2];
    sub(/[\.\/]*/,"",pkgdir);
    if(pkgdir !~ /\//) {
      pkgcat=pkg;
      gsub(/\/.*/,"",pkgcat);
      pkgdir=pkgcat "/" pkgdir;
      if(debug) printf("Corrected missing category directory to get \"%s\"\n",pkgdir) > "/dev/stderr";
    }
    if(debug){
      printf("package in directory %s %s on:\n",pkg,deptype) > "/dev/stderr";
      printf("\tpkgpat = %s\n",pkgpat) > "/dev/stderr";
      printf("\tpkgdir = %s\n",pkgdir) > "/dev/stderr";
    }

# mark this package directory as being one which is depended upon
    depended_on_pkgs[pkgdir] = 1;

  }
  next;
}


END {
  i=0;
  for(pkg in depended_on_pkgs) {
    if(pkg in depended_pkgs) {
      if(debug) printf("Package: %s is already depended\n",pkg) > "/dev/stderr";
    }
    else {
      if(debug)printf("Package: %s is NOT depended\n",pkg) > "/dev/stderr";
      not_depended[i]=pkg;
      i++;
    }
  }

  i=0;
  while(i in not_depended) {
    printf("%s\n",not_depended[i]);
    i++;
  }
  close("/dev/stderr");

  exit(0);
}
