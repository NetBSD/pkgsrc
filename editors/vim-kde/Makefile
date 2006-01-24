# $NetBSD: Makefile,v 1.31 2006/01/24 07:32:06 wiz Exp $

DISTNAME=	kvim-${KVIM_VERSION}
PKGNAME=	vim-kde-${KVIM_VERSION}
PKGREVISION=	4
CATEGORIES=	editors kde
MASTER_SITES=	ftp://ftp.rutgers.edu/pub/kde/stable/apps/KDE3.x/utils/ \
		ftp://ftp.kde.org/pub/kde/stable/apps/KDE3.x/utils/ \
		http://freenux.org/kvim/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.freehackers.org/kvim
COMMENT=	Vim editor (vi clone) with X11 KDE3 GUI

BROKEN_IN=	pkgsrc-2005Q4

KVIM_VERSION=	6.2.14

CONFLICTS+=	vim-gtk-[0-9]* vim-gtk2-[0-9]* vim-motif-[0-9]*
CONFLICTS+=	vim-share-[0-9]* vim-[0-9]* vim-xaw-[0-9]*
CONFLICTS+=	pkg_alternatives-[0-9]*

WRKSRC= 		${WRKDIR}/kvim-${KVIM_VERSION}/src
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
