# $NetBSD: Makefile,v 1.5 2001/05/17 12:33:04 hubertf Exp $
#

DISTNAME=	smpeg-0.4.3
CATEGORIES=	devel
MASTER_SITES=	ftp://sunsite.auc.dk/pub/os/linux/loki/open-source/smpeg/ \
		ftp://ftp.linuxgames.com/loki/open-source/smpeg/

MAINTAINER=	wulf@netbsd.org
HOMEPAGE=	http://www.lokigames.com/development/smpeg.php3
COMMENT=	SDL MPEG Player Library

DEPENDS+=	SDL>=1.1.5nb1:../../devel/SDL
DEPENDS+=	gtk+-1.*:../../x11/gtk

USE_GMAKE=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"
