# $NetBSD: Makefile,v 1.10 2024/11/26 11:53:30 adam Exp $

DISTNAME=	npth-1.8
CATEGORIES=	devel
MASTER_SITES=	https://gnupg.org/ftp/gcrypt/npth/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ada@netbsdfr.org
HOMEPAGE=	https://www.gnupg.org/software/npth/index.html
COMMENT=	New Portable Threads Library (nPth)
LICENSE=	gnu-lgpl-v2.1

USE_CC_FEATURES=	c99
USE_LANGUAGES=		c
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
TEST_TARGET=		check
PKGCONFIG_OVERRIDE+=	npth.pc.in

.include "../../mk/bsd.pkg.mk"
