# $NetBSD: Makefile,v 1.6 2001/06/26 10:18:56 zuntum Exp $
#

DISTNAME=	smpeg-0.4.3
CATEGORIES=	devel
MASTER_SITES=	ftp://sunsite.auc.dk/pub/os/linux/loki/open-source/smpeg/ \
		ftp://ftp.linuxgames.com/loki/open-source/smpeg/

MAINTAINER=	wulf@netbsd.org
HOMEPAGE=	http://www.lokigames.com/development/smpeg.php3
COMMENT=	SDL MPEG Player Library

USE_BUILDLINK_ONLY=	YES
USE_CONFIG_WRAPPER=	YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

.include "../../devel/SDL/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
