# $NetBSD: Makefile,v 1.1.1.1 1999/09/17 14:40:45 fredb Exp $
#

DISTNAME=	maketool-0.3
CATEGORIES=	devel
MASTER_SITES=	http://www.alphalink.com.au/~gnb/maketool/
EXTRACT_SUFX=	-src.tgz

MAINTAINER=	fb@enteract.com
HOMEPAGE=	http://www.alphalink.com.au/~gnb/#maketool

DEPENDS+=	gettext-0.10.35:../../devel/gettext
DEPENDS+=	gtk+-1.2.4:../../x11/gtk

USE_GMAKE=	yes
USE_X11BASE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-included-gettext
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"

post-patch:
	cd ${WRKSRC}; \
	${CP} filter.c filter.c.dist; \
	${CP} preferences.c preferences.c.dist; \
	${SED} 's|^make|${GMAKE}|' >extract_targets <extract_targets.sh; \
	${SED} 's|\^make|${GMAKE}|' >filter.c <filter.c.dist; \
	${SED} '/prefs.prog/s|\"make |\"${GMAKE} |' >preferences.c <preferences.c.dist

.include "../../mk/bsd.pkg.mk"
