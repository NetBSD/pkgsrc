# $NetBSD: Makefile,v 1.9.2.1 2003/03/15 12:11:44 grant Exp $

DISTNAME=		qcad-1.4.7-src
PKGNAME=		qcad-1.4.7
PKGREVISION=		1
CATEGORIES=		cad
MASTER_SITES=		http://www.qcad.org/archives/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.qcad.org/
COMMENT=		2D CAD System

USE_BUILDLINK2=		# defined
USE_X11=		# defined
MAKE_ENV+=		MACHINE_ARCH=${MACHINE_ARCH}

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

.include "../../x11/qt2-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
