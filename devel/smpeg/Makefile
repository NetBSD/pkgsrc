# $NetBSD: Makefile,v 1.11 2001/06/29 04:54:52 jlam Exp $
#

DISTNAME=	smpeg-0.4.3
CATEGORIES=	devel
MASTER_SITES=	ftp://sunsite.auc.dk/pub/os/linux/loki/open-source/smpeg/ \
		ftp://ftp.linuxgames.com/loki/open-source/smpeg/

MAINTAINER=	wulf@netbsd.org
HOMEPAGE=	http://www.lokigames.com/development/smpeg.php3
COMMENT=	SDL MPEG Player Library

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

USE_BUILDLINK_ONLY=	yes
REPLACE_BUILDLINK=	smpeg-config

CPPFLAGS+=		-Dunix=1

.include "../../devel/SDL/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
