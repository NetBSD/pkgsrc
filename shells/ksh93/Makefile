# $NetBSD: Makefile,v 1.9 2023/09/18 14:11:41 vins Exp $

DISTNAME=	ksh93-1.0.7
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GITHUB:=ksh93/}
GITHUB_PROJECT=	ksh
GITHUB_TAG=	v${PKGVERSION:S/beta/-beta/}

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	http://www.kornshell.com/
COMMENT=	Actively developed fork of AT&T KornShell 93u+
LICENSE=	epl-v1.0

CONFLICTS+=		ast-ksh-[0-9]* static-ast-ksh-[0-9]*

USE_TOOLS+=		ksh
USE_CC_FEATURES=	c11

CFLAGS.SunOS+=	-D__EXTENSIONS__

FORTIFY_SUPPORTED=	no

MAKE_ENV+=		SHELL=${KSH}
MAKE_ENV+=		CCFLAGS=${CFLAGS:M*:Q}

TEST_TARGET=	test
PKG_SHELL=	bin/ksh93

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} 		\
		${KSH} ./bin/package make ${MAKEFLAGS}

do-install:
	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV}	\
		${KSH} ./bin/package install ${DESTDIR}${PREFIX}

.include "../../mk/bsd.pkg.mk"
