# $NetBSD: Makefile,v 1.14 2014/06/22 14:50:47 bsiegert Exp $

VERSION=	1.3
DISTNAME=	go${VERSION}.src
PKGNAME=	go-${VERSION}
CATEGORIES=	lang
MASTER_SITES=	https://storage.googleapis.com/golang/
PATCH_SITES=	https://codereview.appspot.com/download/

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	http://golang.org/
COMMENT=	The Go programming language
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/go
USE_TOOLS+=	bash:run perl:run pax

# uses ulimit -T
BUILD_DEPENDS+=	bash>=4.2nb3:../../shells/bash

.include "../../mk/bsd.prefs.mk"

# TODO: other arm platforms?
ONLY_FOR_PLATFORM= *-*-i386 *-*-x86_64 *-*-evbarm
.if ${MACHINE_ARCH} == "i386"
GOARCH=		386
GO_COMPILER=    8
.elif ${MACHINE_ARCH} == "x86_64"
GOARCH=		amd64
GO_COMPILER=    6
.elif ${MACHINE_ARCH} == "evbarm"
GOARCH=		arm
GO_COMPILER=    5
.endif
PLIST_SUBST+=	GO_PLATFORM=${LOWER_OPSYS:Q}_${GOARCH:Q} GOARCH=${GOARCH:Q}
PLIST_SUBST+=  GO_COMPILER=${GO_COMPILER:Q}

# cgo compiles under TMPDIR
TMPDIR?=	/tmp
BUILDLINK_PASSTHRU_DIRS+= ${TMPDIR}

# bash script may use unportable bash constructs
CHECK_PORTABILITY_SKIP=	lib/time/update.bash

GOROOT_FINAL=	${PREFIX}/go
INSTALLATION_DIRS= bin

REPLACE_BASH+=	doc/articles/wiki/test.bash
REPLACE_BASH+=	doc/codewalk/run
REPLACE_BASH+=	doc/progs/run
REPLACE_BASH+=	doc/progs/update.bash
REPLACE_BASH+=	misc/arm/a
REPLACE_BASH+=	misc/benchcmp
REPLACE_BASH+=	misc/cgo/testso/test.bash
REPLACE_BASH+=	misc/makerelease/darwin/scripts/postinstall
REPLACE_BASH+=	misc/makerelease/darwin/scripts/preinstall
REPLACE_BASH+=	misc/nacl/go_nacl_386_exec
REPLACE_BASH+=	misc/nacl/go_nacl_amd64p32_exec
REPLACE_BASH+=	misc/vim/ftplugin/go/test.sh
REPLACE_BASH+=	misc/xcode/4/go4xcode.sh
REPLACE_BASH+=	src/all.bash
REPLACE_BASH+=	src/clean.bash
REPLACE_BASH+=	src/cmd/go/test.bash
REPLACE_BASH+=	src/make.bash
REPLACE_BASH+=	src/nacltest.bash
REPLACE_BASH+=	src/pkg/runtime/mknacl.sh
REPLACE_BASH+=	src/pkg/syscall/mkall.sh
REPLACE_BASH+=	src/pkg/syscall/mkerrors.sh
REPLACE_BASH+=	src/race.bash
REPLACE_BASH+=	src/run.bash
REPLACE_BASH+=	src/sudo.bash
REPLACE_BASH+=	test/bench/shootout/timing.sh
REPLACE_BASH+=	test/run

REPLACE_PERL+=	misc/pprof
REPLACE_PERL+=	misc/xcode/4/go4xcode.sh
REPLACE_PERL+=	src/pkg/net/http/cgi/testdata/test.cgi
REPLACE_PERL+=	src/pkg/regexp/syntax/make_perl_groups.pl
REPLACE_PERL+=	src/pkg/syscall/mksyscall.pl
REPLACE_PERL+=	src/pkg/syscall/mksyscall_solaris.pl
REPLACE_PERL+=	src/pkg/syscall/mksysctl_openbsd.pl
REPLACE_PERL+=	src/pkg/syscall/mksysnum_darwin.pl
REPLACE_PERL+=	src/pkg/syscall/mksysnum_dragonfly.pl
REPLACE_PERL+=	src/pkg/syscall/mksysnum_freebsd.pl
REPLACE_PERL+=	src/pkg/syscall/mksysnum_linux.pl
REPLACE_PERL+=	src/pkg/syscall/mksysnum_netbsd.pl
REPLACE_PERL+=	src/pkg/syscall/mksysnum_openbsd.pl
REPLACE_PERL+=	test/errchk

# uses /bin/rc (for Plan 9)
CHECK_INTERPRETER_SKIP+=	go/include/plan9/mklibc.rc
CHECK_INTERPRETER_SKIP+=	go/src/all.rc
CHECK_INTERPRETER_SKIP+=	go/src/clean.rc
CHECK_INTERPRETER_SKIP+=	go/src/make.rc
CHECK_INTERPRETER_SKIP+=	go/src/run.rc

do-build:
	cd ${WRKSRC}/src && env GOROOT_FINAL=${GOROOT_FINAL:Q} ${BASH} ./make.bash

do-install:
	cd ${WRKSRC} && rm -rf .hgignore .hgtags pkg/obj
	cd ${WRKDIR} && pax -rw go ${DESTDIR}${PREFIX}
	find ${DESTDIR}${PREFIX}/go/src -name \*.orig -exec rm {} \;
.for cmd in go gofmt
	cd ${DESTDIR}${PREFIX}/bin && ln -sf ../go/bin/${cmd} ${cmd}
.endfor

.include "../../mk/bsd.pkg.mk"
