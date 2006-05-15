# $NetBSD: Makefile,v 1.17 2006/05/15 22:47:20 joerg Exp $

DISTNAME=	xtide-2.4
PKGREVISION=	5
CATEGORIES= 	misc x11
MASTER_SITES=	ftp://ftp.flaterco.com/xtide/
DISTFILES=	${XTIDE_SRC} harmonics.txt.gz offsets.xml.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.flaterco.com/
COMMENT=	X11 tide predictor

EXTRACT_ONLY=	${XTIDE_SRC}
XTIDE_SRC=	${DISTNAME}${EXTRACT_SUFX}

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c++

CONFIGURE_ARGS+=--sysconfdir=${PKG_SYSCONFDIR:Q}
EGDIR=		${PREFIX}/share/examples/xtide
CONF_FILES=	${EGDIR}/xtide.conf ${PKG_SYSCONFDIR}/xtide.conf

post-patch:
	@cd ${WRKSRC}/DOCUMENTATION;					\
	for f in *; do							\
		${MV} $$f $$f.bak;					\
		${SED} -e 's|/usr/local|${PREFIX}|g' < $$f.bak > $$f;	\
	done

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/xtide
	${INSTALL_DATA_DIR} ${EGDIR}
	${GZCAT} ${DISTDIR}/harmonics.txt.gz > ${WRKDIR}/harmonics.txt
	${GZCAT} ${DISTDIR}/offsets.xml.gz > ${WRKDIR}/offsets.xml
	${CP} ${FILESDIR}/xtide.conf ${EGDIR}/xtide.conf
	${CP} ${WRKDIR}/harmonics.txt ${PREFIX}/share/xtide
	${CP} ${WRKDIR}/offsets.xml ${PREFIX}/share/xtide

.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
