# $NetBSD: Makefile,v 1.9 2004/04/24 22:46:11 jlam Exp $

DISTNAME=	xspeakfree-0.8.1
PKGREVISION=	1
CATEGORIES=	net audio x11
MASTER_SITES=	http://www.spearce.org/projects/xspeakfree/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.spearce.org/projects/xspeakfree/
COMMENT=	Tcl/Tk (wish) frontend to Speak Freely

DEPENDS+=	speakfreely>=7.1:../../net/speakfreely
DEPENDS+=	tk>=8.3.2:../../x11/tk83

NO_BUILD=	yes

WISH=		${LOCALBASE}/bin/wish

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
