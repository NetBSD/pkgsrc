# $NetBSD: Makefile,v 1.7 2007/12/14 08:34:42 bjs Exp $

DISTNAME=	tre-0.7.5
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://laurikari.net/tre/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://laurikari.net/tre/
COMMENT=	Lightweight and robust POSIX compliant regexp matching library

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

CONFIGURE_ARGS+=	--disable-agrep
CONFIGURE_ARGS+=	--disable-system-abi

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
