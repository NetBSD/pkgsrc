# $NetBSD: Makefile,v 1.3 2022/07/03 21:19:31 leot Exp $

DISTNAME=	ksh93-1.0.0beta.2
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GITHUB:=ksh93/}
GITHUB_PROJECT=	ksh
GITHUB_TAG=	v${PKGVERSION:S/beta/-beta/}

MAINTAINER=	vms@retrobsd.ddns.net
HOMEPAGE=	https://github.com/ksh93/ksh/
COMMENT=	Actively developed fork of AT&T KornShell 93u+
LICENSE=	epl-v1.0

CONFLICTS+=		ast-ksh-[0-9]* static-ast-ksh-[0-9]*

FORTIFY_SUPPORTED=	no

KSH=	${TOOLS_PATH.ksh:Q}

MAKEFLAGS+=		CC=${CC:Q} SHELL=${KSH}
MAKEFLAGS+=		CCFLAGS=${CFLAGS:M*:Q}

CFLAGS.SunOS+=	-std=c11 -D__EXTENSIONS__

PKG_SHELL=		bin/ksh93

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} 				\
		${KSH} ./bin/package make ${MAKEFLAGS}

do-install:
	set -e;								\
	arch=`${WRKSRC}/bin/package host`;                              \
	${INSTALL_PROGRAM} ${WRKSRC}/arch/"$${arch}"/bin/ksh 		\
		${DESTDIR}${PREFIX}/bin/ksh93

	${INSTALL_MAN} ${WRKSRC}/src/cmd/ksh93/sh.1 			\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/ksh93.1

do-test:
	cd ${WRKSRC} && ${SETENV} SHELL=${KSH}				\
		${KSH} ./bin/package test

.include "../../mk/bsd.pkg.mk"
