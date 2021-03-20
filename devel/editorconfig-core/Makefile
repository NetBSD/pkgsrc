# $NetBSD: Makefile,v 1.4 2021/03/20 18:52:45 adam Exp $

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

.include "options.mk"

.include "../../devel/pcre2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
