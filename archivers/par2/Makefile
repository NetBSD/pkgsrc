# $NetBSD: Makefile,v 1.36 2026/02/09 13:58:37 adam Exp $

DISTNAME=	par2cmdline-1.1.1
PKGNAME=	${DISTNAME:S/cmdline//}
CATEGORIES=	archivers misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=Parchive/}
GITHUB_PROJECT=	par2cmdline
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Parchive/par2cmdline
COMMENT=	PAR 2.0 compatible file verification and repair tool
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
