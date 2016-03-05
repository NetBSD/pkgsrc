# $NetBSD: Makefile,v 1.26 2016/03/05 11:28:42 jperkin Exp $
#

DISTNAME=	kimera-2.11
PKGREVISION=	22
CATEGORIES=	inputmethod japanese
MASTER_SITES=	${MASTER_SITE_OSDN:=kimera/37271/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://kimera.osdn.jp/
COMMENT=	Kanji Input MEthod for RAgamuffins
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c++

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}

do-configure:
	${RUN} cd ${WRKSRC}; \
	${SETENV} ${CONFIGURE_ENV} ${QTDIR}/bin/qmake \
		target.path=${PREFIX}/libdata/kimera \
		script.path=${PREFIX}/bin \
		kimera.pro

.if !exists(/usr/include/alloca.h)
SUBST_CLASSES+=		alloca
SUBST_STAGE.alloca=	post-configure
SUBST_FILES.alloca=	src/inputmethod.cpp
SUBST_SED.alloca=	-e 's|<alloca.h>|<stdlib.h>|g'
.endif

.include "../../inputmethod/anthy/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
