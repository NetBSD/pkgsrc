# $NetBSD: Makefile,v 1.49 2008/01/09 13:47:43 martti Exp $

DISTNAME=	kvim-${KVIM_VERSION}
PKGNAME=	vim-kde-${KVIM_VERSION}
PKGREVISION=	14
CATEGORIES=	editors kde
MASTER_SITES=	${MASTER_SITE_KDE:=apps/KDE3.x/utils/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
# HOMEPAGE=	http://www.freehackers.org/kvim
# AWOL
COMMENT=	Vim editor (vi clone) with X11 KDE3 GUI

KVIM_VERSION=	6.2.14

CONFLICTS+=	vim-gtk-[0-9]* vim-gtk2-[0-9]* vim-motif-[0-9]*
CONFLICTS+=	vim-share-[0-9]* vim-[0-9]* vim-xaw-[0-9]*
CONFLICTS+=	pkg_alternatives-[0-9]*

WRKSRC=		${WRKDIR}/kvim-${KVIM_VERSION}/src
USE_TOOLS+=	awk:run perl:run msgfmt
MAKE_ENV+=	AWK=${AWK:Q}
MAKE_ENV+=	PERL5=${PERL5:Q}

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-gui=kde
CONFIGURE_ARGS+=	--enable-kde-toolbar
CONFIGURE_ARGS+=	--with-features=huge
CONFIGURE_ARGS+=	--with-tlib=ncurses

post-configure:
	${TOUCH} ${WRKSRC}/auto/configure ${WRKSRC}/auto/config.mk

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
