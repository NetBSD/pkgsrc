# $NetBSD: Makefile,v 1.3 2023/02/04 13:23:05 taca Exp $

DISTNAME=	0.29.0.gfm.9
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=github/}
GITHUB_PROJECT=	cmark-gfm
GITHUB_TAG=	${DISTNAME}
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
