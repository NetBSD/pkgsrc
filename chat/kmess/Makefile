# $NetBSD: Makefile,v 1.25 2006/04/17 13:46:18 wiz Exp $
#

DISTNAME=	kmess-1.1
PKGREVISION=	11
CATEGORIES=	chat kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kmess/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://kmess.sourceforge.net/
COMMENT=	MSN Messenger Client for KDE3

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake msgfmt
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes

.include "../../audio/arts/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
