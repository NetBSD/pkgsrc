# $NetBSD: Makefile,v 1.9 2001/06/28 21:29:29 jlam Exp $
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
GNU_CONFIGURE=	yes

USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
