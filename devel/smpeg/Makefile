# $NetBSD: Makefile,v 1.17 2003/07/17 21:34:02 grant Exp $
#

DISTNAME=	smpeg-0.4.4
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	ftp://sunsite.auc.dk/pub/os/linux/loki/open-source/smpeg/ \
		ftp://ftp.linuxgames.com/loki/open-source/smpeg/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://www.lokigames.com/development/smpeg.php3
COMMENT=	SDL MPEG Player Library

USE_BUILDLINK2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_X11=	yes

USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

CPPFLAGS+=		-Dunix=1

.include "../../devel/SDL/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
