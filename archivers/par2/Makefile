# $NetBSD: Makefile,v 1.40 2026/08/30 01:13:18 gdt Exp $

DISTNAME=	par2cmdline-1.3.0
PKGNAME=	${DISTNAME:S/cmdline//}
PKGREVISION=	1
CATEGORIES=	archivers misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=Parchive/}
GITHUB_PROJECT=	par2cmdline
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Parchive/par2cmdline
COMMENT=	PAR 2.0 compatible file verification and repair tool
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
# Makefile.am has hard-code --std=c++14 with no configure check.
# Not reported upstream because nobody would use gcc < 5.
USE_CXX_FEATURES=	c++14
GNU_CONFIGURE=		yes
TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
