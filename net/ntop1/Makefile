# $NetBSD: Makefile,v 1.4 2006/03/04 21:30:21 jlam Exp $

DISTNAME=		ntop-1.1
PKGREVISION=		4
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.unipi.it/pub/local/ntop/source/
EXTRACT_SUFX=		-src.tar.gz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.ntop.org/
COMMENT=		Shows network usage (similar to "top" for processes)

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-threads=no

INSTALL_TARGET=		install install-man

.include "../../net/libpcap/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
