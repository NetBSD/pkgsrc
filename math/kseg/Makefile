# $NetBSD: Makefile,v 1.6 2012/09/11 23:04:22 asau Exp $
#

DISTNAME=	kseg-0.403
PKGREVISION=	3
CATEGORIES=	math
MASTER_SITES=	http://www.mit.edu/~ibaran/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mit.edu/~ibaran/kseg.html
COMMENT=	Interactive geometry program
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/kseg
USE_LANGUAGES=	c++
INSTALLATION_DIRS+= bin share/kseg

PREV_PKGPATH=	misc/kseg

KSEGLANG=	${PREFIX}/share/kseg/lang
SUBST_CLASSES+= prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	main.cpp
SUBST_VARS.prefix=	KSEGLANG

do-configure:
	cd ${WRKSRC} && env ${CONFIGURE_ENV} ${QTDIR}/bin/qmake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/kseg ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${KSEGLANG}
	for f in ${WRKSRC}/*.qm ${WRKSRC}/*.html; do \
		${INSTALL_DATA} $$f ${DESTDIR}${KSEGLANG}; \
	done
	${CP} -r ${WRKSRC}/examples ${DESTDIR}${PREFIX}/share/kseg
	${CHMOD} 644 ${DESTDIR}${PREFIX}/share/kseg/examples/*

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
