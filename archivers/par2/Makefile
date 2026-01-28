# $NetBSD: Makefile,v 1.35 2026/01/28 17:36:46 rhialto Exp $

DISTNAME=	par2cmdline-1.1.0
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
