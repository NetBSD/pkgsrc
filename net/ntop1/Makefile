# $NetBSD: Makefile,v 1.6 2007/12/22 11:48:09 obache Exp $

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
INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../net/libpcap/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
