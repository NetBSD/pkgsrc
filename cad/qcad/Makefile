# $NetBSD: Makefile,v 1.8 2002/03/13 17:36:40 fredb Exp $

DISTNAME=		qcad-1.4.7-src
PKGNAME=		qcad-1.4.7
PKGREVISION=		1
CATEGORIES=		cad
MASTER_SITES=		http://www.qcad.org/archives/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.qcad.org/
COMMENT=		2D CAD System

USE_BUILDLINK_ONLY=	# defined

do-configure:
	@for f in rappwin.cpp rconfig.cpp relement.cpp rfile.cpp	\
	rfonts.cpp; do							\
		${SED} -e 's:@PREFIX@:'${PREFIX}':g' ${WRKSRC}/$$f	\
		> ${WRKSRC}/$$f.tmp && ${MV} ${WRKSRC}/$$f.tmp		\
		${WRKSRC}/$$f;						\
	done

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qcad ${PREFIX}/bin
	for f in `${FIND} ${WRKSRC} -type f -print`; do			\
	${CHOWN} ${SHAREOWN}:${SHAREGRP} $$f;				\
	${CHMOD} ${SHAREMODE} $$f;					\
	done
	for f in `${FIND} ${WRKSRC} -type d -print`; do 		\
	${CHOWN} ${SHAREOWN}:${SHAREGRP} $$f; 				\
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/qcad
	(cd ${WRKSRC}; ${GTAR} cf - AUTHORS COPYING README		\
	TODO cur doc examples fonts hatches libraries messages xpm) |	\
	(cd ${PREFIX}/share/qcad; ${GTAR} vxf - )

.include "../../x11/qt2-libs/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
