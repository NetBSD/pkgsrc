# $NetBSD: Makefile,v 1.3 2002/11/10 00:35:07 grant Exp $

DISTNAME=	kvim-${KVIM_VERSION}
PKGNAME=	vim-kde-${KVIM_VERSION}
WRKSRC= 	${WRKDIR}/kvim-${KVIM_VERSION}/src
CATEGORIES=	editors kde
MASTER_SITES=	http://download.kde.org/stable/apps/KDE3.x/utils/ \
		http://freenux.org/kvim/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	greyskyy@po.cwru.edu
HOMEPAGE=	http://www.freehackers.org/kvim
COMMENT=	Vim editor (vi clone) with X11 KDE3 GUI

KVIM_VERSION=	6.1.141

CONFLICTS+=	vim-gtk-[0-9]* vim-share-[0-9]* vim-[0-9]* vim-xaw-[0-9]*

USE_BUILDLINK2=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-gui=kde
CONFIGURE_ARGS+=	--enable-kde-toolbar
CONFIGURE_ARGS+=	--with-features=huge
CONFIGURE_ARGS+=	--with-tlib=ncurses

.include "../../devel/ncurses/buildlink2.mk"
.include "../../x11/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
