# $NetBSD: Makefile,v 1.10 2023/09/19 22:18:02 vins Exp $

DISTNAME=	ksh93-1.0.7
PKGREVISION=	1
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GITHUB:=ksh93/}
GITHUB_PROJECT=	ksh
GITHUB_TAG=	v${PKGVERSION:S/beta/-beta/}

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	http://www.kornshell.com/
COMMENT=	Actively developed fork of AT&T KornShell 93u+
LICENSE=	epl-v1.0

CONFLICTS+=		ast-ksh-[0-9]* static-ast-ksh-[0-9]*

USE_CC_FEATURES=	c11

CFLAGS.SunOS+=	-D__EXTENSIONS__

FORTIFY_SUPPORTED=	no

MAKE_FLAGS+=		SHELL=${SH:Q} CC=${CC:Q} \
			CCFLAGS=${CFLAGS:M*:Q}

PKG_SHELL=	bin/ksh93

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} 		\
		${SH} ./bin/package make ${MAKE_FLAGS}

do-install:
	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV}	\
		${SH} ./bin/package install ${DESTDIR}${PREFIX}

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV}		\
		${SH} ./bin/package test

.include "../../mk/bsd.pkg.mk"
