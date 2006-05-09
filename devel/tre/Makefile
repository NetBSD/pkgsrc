# $NetBSD: Makefile,v 1.2 2006/05/09 12:34:18 adrianp Exp $

DISTNAME=	tre-0.7.2
CATEGORIES=	devel
MASTER_SITES=	http://laurikari.net/tre/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://laurikari.net/tre/
COMMENT=	Lightweight and robust POSIX compliant regexp matching library

#
# Please do not update or modify this package as it has been imported only
# as a dependecy for chat/unrealircd. This package should only be updated
# when chat/unrealircd requires it.
#

GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--disable-agrep
CONFIGURE_ARGS+=	--disable-shared
CONFIGURE_ARGS+=	--disable-system-abi
CONFIGURE_ARGS+=	--disable-wchar
CONFIGURE_ARGS+=	--disable-multibyte

.include "../../mk/bsd.pkg.mk"
