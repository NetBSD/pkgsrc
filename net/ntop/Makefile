# $NetBSD: Makefile,v 1.21 2001/09/10 17:33:40 wiz Exp $

DISTNAME=		ntop-1.1
PKGNAME=		ntop-1.1nb1
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.unipi.it/pub/local/ntop/source/
EXTRACT_SUFX=		-src.tar.gz

MAINTAINER=		kim@tac.nyc.ny.us
HOMEPAGE=		http://www.ntop.org/
COMMENT=		shows network usage (similar to "top" for processes)

USE_BUILDLINK_ONLY=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-threads=no

INSTALL_TARGET=		install install-man

.include "../../net/libpcap/buildlink.mk"
.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
