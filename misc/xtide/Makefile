# $NetBSD: Makefile,v 1.2 2002/01/21 14:01:23 dmcmahill Exp $

DISTNAME=	xtide-2.4
PKGNAME=	${DISTNAME}
CATEGORIES= 	misc x11
MASTER_SITES=	ftp://ftp.flaterco.com/xtide/
DISTFILES=	${XTIDE_SRC} harmonics.txt.gz offsets.xml.gz

MAINTAINER=	paul@whooppee.com
HOMEPAGE=	http://www.flaterco.com/
COMMENT=	X11 tide predictor

DEPENDS+=	png>0.96:../../graphics/png

EXTRACT_ONLY=	${XTIDE_SRC}
XTIDE_SRC=	${DISTNAME}${EXTRACT_SUFX}

GNU_CONFIGURE=	yes
USE_X11=	yes
USE_XPM=	yes

post-patch:
	@cd ${WRKSRC}/DOCUMENTATION;					\
	for f in *; do							\
		${MV} $$f $$f.bak;					\
		${SED} -e 's|/usr/local|${PREFIX}|g' < $$f.bak > $$f;	\
	done

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/xtide
	${GZCAT} ${DISTDIR}/harmonics.txt.gz > ${WRKDIR}/harmonics.txt
	${GZCAT} ${DISTDIR}/offsets.xml.gz > ${WRKDIR}/offsets.xml
	${CP} ${FILESDIR}/xtide.conf ${PREFIX}/share/examples/xtide.conf
	${CP} ${WRKDIR}/harmonics.txt ${PREFIX}/share/xtide
	${CP} ${WRKDIR}/offsets.xml ${PREFIX}/share/xtide

.include "../../mk/bsd.pkg.mk"
