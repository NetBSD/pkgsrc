# $NetBSD: Makefile,v 1.3 2000/02/09 17:14:27 agc Exp $

DISTNAME=	tkpiechart-5.3
CATEGORIES=	graphics
MASTER_SITES=	http://www.multimania.com/jfontain/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.mygale.org/~jfontain/

DEPENDS+=	tk-8.0.5:../../x11/tk80
DEPENDS+=	stooop-3.7:../../devel/stooop

NO_CONFIGURE=	yes
NO_BUILD=	yes

pre-patch:
	for f in source.tcl instapkg.tcl; do				\
		${MV} ${WRKSRC}/$$f ${WRKSRC}/$$f-prepatch;		\
		${SED} -e '/Id/s|\$$||g' ${WRKSRC}/$$f-prepatch > ${WRKSRC}/$$f; \
	done

post-patch:
	${CHMOD} a+x ${WRKSRC}/instapkg.tcl

do-install:
	${MKDIR} ${PREFIX}/lib/tkpiechart
	cd ${WRKSRC}; ./instapkg.tcl ${PREFIX}/lib/tkpiechart

.include "../../mk/bsd.pkg.mk"
