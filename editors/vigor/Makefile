# $NetBSD: Makefile,v 1.3 2000/01/21 14:54:05 jdolecek Exp $
#

DISTNAME=	vigor-0.010
CATEGORIES=	editors
MASTER_SITES=	http://www.red-bean.com:8080/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.red-bean.com/~joelh/vigor/

DEPENDS+=	tk-8.0.*:../../x11/tk80

CONFLICTS+=	nvi-*

USE_X11=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-x
#		--enable-perlinterp \
#		--disable-curses \
#		--disable-db \
#		--disable-re
CONFIGURE_ENV+=	ADDCPPFLAGS="	-I${LOCALBASE}/include/tcl8.0 \
				-I${LOCALBASE}/include/tk8.0" \
		ADDLDFLAGS="	-L${LOCALBASE}/lib"

post-build:
	nroff -mandoc ${WRKSRC}/../docs/USD.doc/vi.man/vi.1 >${WRKSRC}/../docs/USD.doc/vi.man/vi.0

.include "../../mk/bsd.pkg.mk"
