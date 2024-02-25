# $NetBSD: Makefile,v 1.9 2024/02/25 15:17:29 wiz Exp $

DISTNAME=	npth-1.7
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/npth/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ada@netbsdfr.org
HOMEPAGE=	ftp://ftp.gnupg.org/gcrypt/npth/
COMMENT=	New Portable Threads Library (nPth)
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c99
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
TEST_TARGET=	check

PKGCONFIG_OVERRIDE+=	npth.pc.in

.include "../../mk/bsd.pkg.mk"
