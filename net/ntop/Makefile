# $NetBSD: Makefile,v 1.20 2001/08/24 11:43:47 abs Exp $

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

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" || ${OPSYS} == "Linux"
DEPENDS+=	libpcap>=0.4:../../net/libpcap
.endif

.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
