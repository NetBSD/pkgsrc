# $NetBSD: Makefile,v 1.22.2.1 2002/07/01 17:45:02 jlam Exp $

DISTNAME=		ntop-1.1
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.unipi.it/pub/local/ntop/source/
EXTRACT_SUFX=		-src.tar.gz

MAINTAINER=		kim@tac.nyc.ny.us
HOMEPAGE=		http://www.ntop.org/
COMMENT=		shows network usage (similar to "top" for processes)

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-threads=no

INSTALL_TARGET=		install install-man

.include "../../net/libpcap/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
