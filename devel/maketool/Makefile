# $NetBSD: Makefile,v 1.2 1999/10/13 11:31:26 fredb Exp $
#

DISTNAME=	maketool-0.4
CATEGORIES=	devel
MASTER_SITES=	http://www.alphalink.com.au/~gnb/maketool/
EXTRACT_SUFX=	-src.tgz

MAINTAINER=	fb@enteract.com
HOMEPAGE=	http://www.alphalink.com.au/~gnb/maketool/

DEPENDS+=	gettext-0.10.35:../../devel/gettext
DEPENDS+=	gtk+-1.2.4:../../x11/gtk

USE_GMAKE=	yes
USE_X11BASE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-included-gettext
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"

post-patch:
	cd ${WRKSRC}; \
	${SED} 's|^make|${GMAKE}|' >extract_targets <extract_targets.sh

.include "../../mk/bsd.pkg.mk"
