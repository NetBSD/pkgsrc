# $NetBSD: Makefile,v 1.1 2015/07/04 05:17:56 ryoon Exp $

DISTNAME=	npth-1.2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/npth/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ada@netbsdfr.org
HOMEPAGE=	ftp://ftp.gnupg.org/gcrypt/npth/
COMMENT=	New Portable Threads Library (nPth)
LICENSE=	gnu-gpl-v3

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

post-build:
	cd ${WRKSRC} && ${RM} npth-config && ${MAKE} npth-config

.include "../../mk/bsd.pkg.mk"
