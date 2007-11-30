# $NetBSD: Makefile,v 1.31 2007/11/30 21:55:04 wiz Exp $
#

DISTNAME=	kmess-1.4.3
PKGREVISION=	4
CATEGORIES=	chat kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kmess/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://kmess.sourceforge.net/
COMMENT=	MSN Messenger Client for KDE3

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake msgfmt
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
