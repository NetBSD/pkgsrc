# $NetBSD: Makefile,v 1.25 2005/01/25 13:48:54 jmmv Exp $

DISTNAME=	kvim-${KVIM_VERSION}
PKGNAME=	vim-kde-${KVIM_VERSION}
PKGREVISION=	2
CATEGORIES=	editors kde
MASTER_SITES=	ftp://ftp.rutgers.edu/pub/kde/stable/apps/KDE3.x/utils/ \
		ftp://ftp.kde.org/pub/kde/stable/apps/KDE3.x/utils/ \
		http://freenux.org/kvim/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	greyskyy@po.cwru.edu
HOMEPAGE=	http://www.freehackers.org/kvim
COMMENT=	Vim editor (vi clone) with X11 KDE3 GUI

KVIM_VERSION=	6.2.14

CONFLICTS+=	vim-gtk-[0-9]* vim-gtk2-[0-9]* vim-motif-[0-9]*
CONFLICTS+=	vim-share-[0-9]* vim-[0-9]* vim-xaw-[0-9]*
CONFLICTS+=	pkg_alternatives-[0-9]*

WRKSRC= 		${WRKDIR}/kvim-${KVIM_VERSION}/src
USE_BUILDLINK3=		YES
USE_DIRS+=		xdg-1.1

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-gui=kde
CONFIGURE_ARGS+=	--enable-kde-toolbar
CONFIGURE_ARGS+=	--with-features=huge
CONFIGURE_ARGS+=	--with-tlib=ncurses

post-configure:
	${TOUCH} ${WRKSRC}/auto/configure ${WRKSRC}/auto/config.mk

.include "../../devel/ncurses/buildlink3.mk"
.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdebase3/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
