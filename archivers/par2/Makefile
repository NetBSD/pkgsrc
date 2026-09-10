# $NetBSD: Makefile,v 1.41 2026/09/10 09:56:15 adam Exp $

DISTNAME=	par2cmdline-1.4.0
PKGNAME=	${DISTNAME:S/cmdline//}
CATEGORIES=	archivers misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=Parchive/}
GITHUB_PROJECT=	par2cmdline
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Parchive/par2cmdline
COMMENT=	PAR 2.0 compatible file verification and repair tool
LICENSE=	gnu-gpl-v2

# Makefile.am has hard-code --std=c++14 with no configure check.
# Not reported upstream because nobody would use gcc < 5.
USE_CXX_FEATURES=	c++14
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
