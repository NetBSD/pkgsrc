# $NetBSD: Makefile,v 1.8 2001/05/05 19:51:15 jlam Exp $

DISTNAME=	tkpiechart-5.4
CATEGORIES=	graphics
MASTER_SITES=	http://jfontain.free.fr/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://jfontain.free.fr/
COMMENT=	Tcl/Tk pie-chart utility; in Tcl, not as an extension

DEPENDS+=	tk>=8.3.2:../../x11/tk
DEPENDS+=	stooop>=3.7:../../devel/stooop

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
	${INSTALL_DATA_DIR} ${PREFIX}/lib/tcl/tkpiechart
	cd ${WRKSRC}; ./instapkg.tcl ${PREFIX}/lib/tcl/tkpiechart

.include "../../mk/bsd.pkg.mk"
