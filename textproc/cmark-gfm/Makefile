# $NetBSD: Makefile,v 1.2 2022/07/25 11:12:29 wiz Exp $

GITHUB_PROJECT=	cmark-gfm
GITHUB_TAG=	${DISTNAME}
DISTNAME=	0.29.0.gfm.0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=github/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/github/cmark-gfm/
COMMENT=	GitHub fork of cmark
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	src/libcmark-gfm.pc.in

.include "../../mk/bsd.pkg.mk"
