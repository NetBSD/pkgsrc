#!/bin/sh
# texlive2pkg
# $NetBSD: texlive2pkg.sh,v 1.1 2016/01/24 19:34:44 markd Exp $
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
pkgtarball=""
doctarball=""

USAGE="${NAME} package-tarball [doc-tarball] -- create a texlive package for pkgsrc"

if [ ${#} -eq 1 ]; then
  pkgtarball=$1
elif [ ${#} -eq 2 ]; then
  pkgtarball=$1
  doctarball=$2
  case $doctarball in
  /*.doc.tar.xz)
     break ;;
  *.doc.tar.xz)
     doctarball=$PWD/$doctarball
     break ;;
  *)
     echo ${USAGE}
     exit 1
  esac
else
  echo ${USAGE}
  exit 1
fi

case $pkgtarball in
/*.tar.xz)
   break ;;
*.tar.xz)
   pkgtarball=$PWD/$pkgtarball
   break ;;
*)
   echo ${USAGE}
   exit 1
esac

if [ ! -f $pkgtarball ]; then
  echo "File not found - $pkgtarball"
  exit 1
fi

(mkdir $TDIR; cd $TDIR ; xzcat $pkgtarball | tar xf - tlpkg)
eval `$LIBEXECDIR/texlive.pkg $TDIR/tlpkg/tlpobj/*.tlpobj`
mkdir -p $DISTDIR/tex-$PKG-$REV
cp $* $DISTDIR/tex-$PKG-$REV/
(cd tex-$PKG; $MAKE makesum)
if [ -f "$doctarball" ]; then
   (cd $TDIR; xzcat $doctarball | tar xf - tlpkg)
   $LIBEXECDIR/texlive.pkg.doc $PKG $REV "$VERSION" "$LICENSE" "$HOMEPAGE" < $TDIR/tlpkg/tlpobj/${PKG}.doc.tlpobj && \
   (cd tex-$PKG-doc; $MAKE makesum)
fi
rm -rf $TDIR
