# $NetBSD: Makefile,v 1.3 2001/05/03 22:02:59 jtb Exp $

DISTNAME=		qcad-1.4.7-src
PKGNAME=		qcad-1.4.7
CATEGORIES=		cad
MASTER_SITES=		http://www.qcad.org/archives/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.qcad.org/
COMMENT=		2D CAD System

DEPENDS+=		qt2-libs>=2.2.4:../../x11/qt2-libs

USE_X11=		#defined

EVAL_PREFIX+=		QT2_PREFIX=qt2
MAKE_ENV+=		QTDIR=${QT2_PREFIX}/qt2

JPEG_PREFIX_DEFAULT=	${LOCALBASE}
EVAL_PREFIX+=		JPEG_PREFIX=jpeg

PNG_PREFIX_DEFAULT=	${LOCALBASE}
EVAL_PREFIX+=		PNG_PREFIX=png

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

.include "../../mk/bsd.pkg.mk"
