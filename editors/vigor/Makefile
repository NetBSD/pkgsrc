# $NetBSD: Makefile,v 1.8 2001/11/15 23:40:32 hubertf Exp $
#

DISTNAME=	vigor-0.016
CATEGORIES=	editors
MASTER_SITES=	http://www.red-bean.com:8080/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.red-bean.com/~joelh/vigor/
COMMENT=	nvi with excessive online "help"

DEPENDS+=	tk>=8.3.2:../../x11/tk

CONFLICTS+=	nvi-[0-9]*

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
