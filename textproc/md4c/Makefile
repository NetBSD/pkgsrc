# $NetBSD: Makefile,v 1.1 2022/11/23 21:50:46 nros Exp $

DISTNAME=	${GITHUB_PROJECT}-${GITHUB_TAG}
PKGNAME=	${DISTNAME:S/release-//}
CATEGORIES=	textproc converters
MASTER_SITES=	${MASTER_SITE_GITHUB:=mity/}
GITHUB_PROJECT=	md4c
GITHUB_TAG=	release-0.4.8 # version is updated here
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mity/md4c/
COMMENT=	Markdown for C library and parser
LICENSE=	mit

WRKSRC=		${WRKDIR}/md4c-release-${PKGVERSION_NOREV}
USE_CMAKE=	yes

PKGCONFIG_OVERRIDE+=	src/md4c-html.pc.in
PKGCONFIG_OVERRIDE+=	src/md4c.pc.in

.include "../../mk/bsd.pkg.mk"
