# $NetBSD: Makefile,v 1.18 2012/09/15 10:04:20 obache Exp $
#

DISTNAME=	qtscriptgenerator-src-0.1.0
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	20
CATEGORIES=	devel
MASTER_SITES=	http://qtscriptgenerator.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/qtscriptgenerator/
COMMENT=	Tool that generates Qt bindings for Qt Script
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c++
USE_LIBTOOL=	yes
MAKE_JOBS_SAFE=	no
INSTALLATION_DIRS=	${QTDIR}/bin ${QTDIR}/plugins/script
INSTALLATION_DIRS+=	share/doc/qtscriptgenerator
INSTALLATION_DIRS+=	share/doc/qtscriptgenerator/examples
INSTALLATION_DIRS+=	share/doc/qtscriptgenerator/examples/images

post-extract:
	${ECHO} "target.path = ${PREFIX}/lib"  >> \
		${WRKSRC}/qtbindings/qtbindingsbase.pri

do-build:
	cd ${WRKSRC}/generator && ${QTDIR}/bin/qmake
	cd ${WRKSRC}/generator && ${SETENV} ${MAKE_ENV} ${MAKE}
	cd ${WRKSRC}/generator && ${SETENV} ${MAKE_ENV} ./generator
	cd ${WRKSRC}/qtbindings && ${QTDIR}/bin/qmake
	cd ${WRKSRC}/qtbindings && ${SETENV} ${MAKE_ENV} ${MAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/generator/generator ${DESTDIR}${QTDIR}/bin
#	${INSTALL_PROGRAM} ${WRKSRC}/tools/qsexec/qsexec ${DESTDIR}${QTDIR}/bin
	cd ${WRKSRC}/plugins/script && \
		libtool --mode=install ${INSTALL_LIB} *.la \
		${DESTDIR}${QTDIR}/plugins/script
	${INSTALL_DATA} ${WRKSRC}/doc/* \
		${DESTDIR}${PREFIX}/share/doc/qtscriptgenerator
	${INSTALL_DATA} ${WRKSRC}/examples/*.* \
		${DESTDIR}${PREFIX}/share/doc/qtscriptgenerator/examples
	${INSTALL_DATA} ${WRKSRC}/examples/images/*.* \
		${DESTDIR}${PREFIX}/share/doc/qtscriptgenerator/examples/images

.include "../../multimedia/phonon/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt4-tools=	full
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
