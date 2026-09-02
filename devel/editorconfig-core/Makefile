# $NetBSD: Makefile,v 1.8 2026/09/02 19:01:24 wiz Exp $

DISTNAME=	editorconfig-core-c-0.12.6
PKGNAME=	${DISTNAME:S/c-//}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=editorconfig/}
GITHUB_PROJECT=	editorconfig-core-c
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nros@NetBSD.org
HOMEPAGE=	http://www.editorconfig.org/
COMMENT=	Editorconfig C library
LICENSE=	2-clause-bsd

PKGCONFIG_OVERRIDE=	src/lib/editorconfig.pc.in

.include "options.mk"

.include "../../devel/cmake/build.mk"

.include "../../devel/pcre2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
