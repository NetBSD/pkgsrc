# $NetBSD: Makefile,v 1.4 2017/03/16 15:01:53 wiz Exp $

DISTNAME=	npth-1.3
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/npth/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ada@netbsdfr.org
HOMEPAGE=	ftp://ftp.gnupg.org/gcrypt/npth/
COMMENT=	New Portable Threads Library (nPth)
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c99
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
TEST_TARGET=	check

CFLAGS.NetBSD+=	-pthread

post-build:
	cd ${WRKSRC} && ${RM} npth-config && ${MAKE} npth-config

.include "../../mk/bsd.pkg.mk"
