# $NetBSD: Makefile,v 1.34 2009/09/03 12:03:37 joerg Exp $

DISTNAME=	WMMail.app-0.64
PKGNAME=	wmmail-0.64
PKGREVISION=	3
CATEGORIES=	mail x11 windowmaker
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	xbiff like "mail-checker" for WindowMaker

PKG_DESTDIR_SUPPORT=	user-destdir

NO_SRC_ON_FTP=	already in MASTER_SITE_LOCAL

#DEPENDS+=	windowmaker>=0.80.0nb1:../../wm/windowmaker

USE_X11BASE=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-PL-incs="-I${LOCALBASE}/include" \
			--with-PL-libs="-L${LOCALBASE}/lib" \
			--x-includes=${X11BASE}/include \
			--x-libraries=${X11BASE}/lib

.include "../../devel/libproplist/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
