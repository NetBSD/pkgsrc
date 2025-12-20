# $NetBSD: Makefile,v 1.4 2025/12/20 16:02:04 wiz Exp $

DISTNAME=	DWB3.3
PKGNAME=	DWB-${GITHUB_TAG}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=n-t-roff/}
GITHUB_PROJECT=	${DISTNAME}
GITHUB_TAG=	20150517

MAINTAINER=	carsten.kunze@arcor.de
HOMEPAGE=	https://github.com/n-t-roff/DWB3.3
COMMENT=	Original Documenter's Workbench Release 3.3
LICENSE=	epl-v1.0

MAKE_FILE=	dwb.mk
USE_LANGUAGES=	c c++
USE_TOOLS+=	flex yacc
MAKE_JOBS_SAFE=	no

MAKE_FLAGS+=	CFLGS=${CFLAGS:Q} LDFLGS=${LDFLAGS:Q}
MAKE_FLAGS+=	OWNER=${ROOT_USER} GROUP=${ROOT_GROUP} ROOT=${DESTDIR}${PREFIX}/DWB
.include "../../mk/compiler.mk"
.if ${CC_VERSION:Mgcc-14.*} || ${CC_VERSION:Mgcc-15.*}
CFLAGS+=	-Wno-implicit-function-declaration
CFLAGS+=	-Wno-implicit-int
.endif

.include "../../mk/bsd.pkg.mk"
