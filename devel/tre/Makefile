# $NetBSD: Makefile,v 1.6 2007/10/13 10:52:30 adrianp Exp $

DISTNAME=	tre-0.7.5
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://laurikari.net/tre/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://laurikari.net/tre/
COMMENT=	Lightweight and robust POSIX compliant regexp matching library

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

CONFIGURE_ARGS+=	--disable-agrep
CONFIGURE_ARGS+=	--disable-system-abi

.include "../../mk/bsd.pkg.mk"
