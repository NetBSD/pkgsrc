# $OpenBSD: Makefile,v 1.5 2001/11/21 01:17:43 naddy Exp $
# $NetBSD: Makefile,v 1.1.1.1 2002/10/04 02:19:13 uebayasi Exp $

DISTNAME=	ast-ksh-${ASTKSH_VERSION}
PKGNAME=	ast-ksh-${ASTKSH_VERSION:S/-//g}
CATEGORIES=	shells
MASTER_SITES=	http://www.research.att.com/~gsf/download/tgz/
DISTFILES=	INIT.${ASTKSH_VERSION}.tgz ast-ksh.${ASTKSH_VERSION}.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.kornshell.com/
COMMENT=	"official AT&T release of KornShell 93"

RESTRICTED=	"Terms for redistribution are not yet clear."
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}
NO_SRC_ON_CDROM=${RESTRICTED}
NO_SRC_ON_FTP=	${RESTRICTED}

ONLY_FOR_PLATFORM=	NetBSD-*-i386

ASTKSH_VERSION=	2002-09-22

WRKSRC=		${WRKDIR}
MAKE_FLAGS=	CC='${CC}' CCFLAGS='${CFLAGS}'

do-build:
	cd ${WRKSRC}; \
	${SETENV} SHELL=${SH} ${SH} ./bin/package ${MAKE_PROGRAM} ${MAKE_FLAGS}

do-install:
	arch=`${WRKSRC}/bin/package host`; \
	${INSTALL_PROGRAM} ${WRKSRC}/arch/$${arch}/bin/ksh \
		${PREFIX}/bin/ksh93; \
	${INSTALL_MAN} ${WRKSRC}/arch/$${arch}/man/man1/sh.1 \
		${PREFIX}/man/man1/ksh93.1

.include "../../mk/bsd.pkg.mk"
