# $NetBSD: Makefile,v 1.14 2003/12/24 09:53:49 jmmv Exp $
#

DISTNAME=	gfract-0.21
PKGREVISION=	3
CATEGORIES=	graphics x11
MASTER_SITES=	http://www.cs.Helsinki.FI/u/salerma/gfract/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} gfract-palettes-0.1.tar.gz

MAINTAINER=	ben@NetBSD.org
HOMEPAGE=	http://www.cs.Helsinki.FI/u/salerma/gfract/
COMMENT=	Gtk-based fractal program

USE_BUILDLINK2=	yes
USE_X11=	yes
ALL_TARGET=	gfract

post-extract:
	${MV} ${WRKDIR}/monk2\'.map ${WRKDIR}/monk2.map
	files="main.c";							\
	cd ${WRKSRC}; for file in $${files}; do				\
		${MV} $${file} $${file}.fixme;				\
		${SED} -e "s|/usr/local/|${PREFIX}/|g"			\
			$${file}.fixme > $${file};			\
		if [ -x $${file}.fixme ]; then				\
			${CHMOD} +x $${file};				\
		fi;							\
		${RM} $${file}.fixme;					\
	done

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/gfract
	${INSTALL_DATA_DIR} ${PREFIX}/share/gfract/palettes
	${INSTALL_DATA} ${WRKDIR}/*.map ${PREFIX}/share/gfract/palettes/
	${INSTALL_DATA} ${WRKSRC}/gfract.xpm ${PREFIX}/share/gfract/
	${INSTALL_PROGRAM} ${WRKSRC}/gfract ${PREFIX}/bin/

.include "../../graphics/png/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
