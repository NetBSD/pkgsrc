# $NetBSD: Makefile,v 1.24 2015/01/16 11:27:03 wiz Exp $

.include "version.mk"

DISTNAME=	go${GO_VERSION}.src
PKGNAME=	go-${GO_VERSION}
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

PLIST_VARS+=	cgo zsyscall

.if ${OPSYS} == "SunOS"
PLIST.zsyscall=	yes
.else
PLIST.cgo=	yes
.endif

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
REPLACE_BASH+=	lib/time/update.bash
REPLACE_BASH+=	misc/arm/a
REPLACE_BASH+=	misc/benchcmp
REPLACE_BASH+=	misc/cgo/errors/test.bash
REPLACE_BASH+=	misc/cgo/testcdefs/test.bash
REPLACE_BASH+=	misc/cgo/testgodefs/test.bash
REPLACE_BASH+=	misc/cgo/testso/test.bash
REPLACE_BASH+=	misc/makerelease/darwin/scripts/postinstall
REPLACE_BASH+=	misc/makerelease/darwin/scripts/preinstall
REPLACE_BASH+=	misc/nacl/go_nacl_386_exec
REPLACE_BASH+=	misc/nacl/go_nacl_amd64p32_exec
REPLACE_BASH+=	misc/nacl/go_nacl_arm_exec
REPLACE_BASH+=	misc/vim/ftplugin/go/test.sh
REPLACE_BASH+=	misc/xcode/4/go4xcode.sh
REPLACE_BASH+=	src/all.bash
REPLACE_BASH+=	src/androidtest.bash
REPLACE_BASH+=	src/clean.bash
REPLACE_BASH+=	src/cmd/go/mkdoc.sh
REPLACE_BASH+=	src/cmd/go/test.bash
REPLACE_BASH+=	src/make.bash
REPLACE_BASH+=	src/nacltest.bash
REPLACE_BASH+=	src/race.bash
REPLACE_BASH+=	src/run.bash
REPLACE_BASH+=	src/runtime/mknacl.sh
REPLACE_BASH+=	src/sudo.bash
REPLACE_BASH+=	src/syscall/mkall.sh
REPLACE_BASH+=	src/syscall/mkerrors.sh
REPLACE_BASH+=	src/syscall/mksysnum_plan9.sh
REPLACE_BASH+=	test/bench/shootout/timing.sh
REPLACE_BASH+=	test/run

REPLACE_PERL+=	misc/pprof
REPLACE_PERL+=	misc/xcode/4/go4xcode.sh
REPLACE_PERL+=	src/net/http/cgi/testdata/test.cgi
REPLACE_PERL+=	src/pkg/net/http/cgi/testdata/test.cgi
REPLACE_PERL+=	src/regexp/syntax/make_perl_groups.pl
REPLACE_PERL+=	src/syscall/*.pl
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
