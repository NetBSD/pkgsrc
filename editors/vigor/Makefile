# $NetBSD: Makefile,v 1.4 2000/08/30 16:20:35 jwise Exp $
#

DISTNAME=	vigor-0.010
CATEGORIES=	editors
MASTER_SITES=	http://www.red-bean.com:8080/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.red-bean.com/~joelh/vigor/

DEPENDS+=	tk-8.3.2:../../x11/tk

CONFLICTS+=	nvi-*

USE_X11=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-x
#		--enable-perlinterp \
#		--disable-curses \
#		--disable-db \
#		--disable-re
CONFIGURE_ENV+=	ADDCPPFLAGS="	-I${LOCALBASE}/include \
				-I${LOCALBASE}/include" \
		ADDLDFLAGS="	-L${LOCALBASE}/lib"

post-build:
	nroff -mandoc ${WRKSRC}/../docs/USD.doc/vi.man/vi.1 >${WRKSRC}/../docs/USD.doc/vi.man/vi.0

.include "../../mk/bsd.pkg.mk"
