# $NetBSD: Makefile,v 1.13 2004/01/20 12:14:06 agc Exp $
#

DISTNAME=	vigor-0.016
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=vigor/}

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://vigor.sourceforge.net/
COMMENT=	nvi with excessive online "help"

CONFLICTS+=	nvi-[0-9]*

WRKSRC=		${WRKDIR}/${DISTNAME}/build
USE_X11=	yes
USE_BUILDLINK2=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-x
#		--enable-perlinterp \
#		--disable-curses \
#		--disable-db \
#		--disable-re
CONFIGURE_ENV+=	ADDCPPFLAGS="	-I${LOCALBASE}/include \
				-I${LOCALBASE}/include" \
		ADDLDFLAGS="	-L${LOCALBASE}/lib"

.if exists(/usr/include/sys/queue.h)
# this file obscures the system header
post-patch:
	${RM} -f ${WRKSRC}/../include/sys/queue.h
.endif

post-build:
	nroff -mandoc ${WRKSRC}/../docs/USD.doc/vi.man/vi.1 >${WRKSRC}/../docs/USD.doc/vi.man/vi.0

.include "../../x11/tk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
