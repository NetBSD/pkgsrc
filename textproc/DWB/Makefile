# $NetBSD: Makefile,v 1.1 2015/08/22 20:51:31 leot Exp $

DISTNAME=	DWB3.3
PKGNAME=	DWB-${GITHUB_TAG}
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
USE_TOOLS+=	lex yacc
MAKE_JOBS_SAFE=	no

MAKE_ENV+=	CFLGS=${CFLAGS:Q} LDFLGS=${LDFLAGS:Q}
MAKE_FLAGS+=	OWNER=${ROOT_USER} GROUP=${ROOT_GROUP} ROOT=${DESTDIR}${PREFIX}/DWB

.include "../../mk/bsd.pkg.mk"
