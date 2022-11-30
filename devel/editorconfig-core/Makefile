# $NetBSD: Makefile,v 1.5 2022/11/30 23:20:25 nros Exp $

DISTNAME=	editorconfig-core-c-0.12.4
PKGNAME=	${DISTNAME:S/c-//}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=editorconfig/}
GITHUB_PROJECT=	editorconfig-core-c
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nros@NetBSD.org
HOMEPAGE=	http://www.editorconfig.org/
COMMENT=	Editorconfig C library
LICENSE=	2-clause-bsd

USE_CMAKE=	yes

PKGCONFIG_OVERRIDE=	src/lib/editorconfig.pc.in

.include "options.mk"

.include "../../devel/pcre2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
