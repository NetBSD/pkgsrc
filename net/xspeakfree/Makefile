# $NetBSD: Makefile,v 1.1.1.1 2000/01/17 17:39:30 jlam Exp $

DISTNAME=	xspeakfree-0.8.1
CATEGORIES=	net audio x11
MASTER_SITES=	http://www.spearce.org/projects/xspeakfree/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.spearce.org/projects/xspeakfree/

DEPENDS+=	speakfreely-7.1:../../net/speakfreely
DEPENDS+=	tk-8.0.*:../../x11/tk80

NO_BUILD=	yes

WISH=		${LOCALBASE}/bin/wish8.0

post-extract:
	${MV} ${WRKSRC}/bin/xspeakfree ${WRKSRC}/bin/xspeakfree.in

do-configure:
	${SED}	-e "s,@PREFIX@,${PREFIX},g" \
		-e "s,@WISH@,${WISH},g" \
		${WRKSRC}/bin/xspeakfree.in > ${WRKSRC}/bin/xspeakfree

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/xspeakfree ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/xspeakfree
	cd ${WRKSRC}/lib/xspeakfree; \
	for file in *.au *.tcl; do \
		${INSTALL_DATA} $${file} ${PREFIX}/share/xspeakfree; \
	done;
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/README.xspeakfree

.include "../../mk/bsd.pkg.mk"
