# $NetBSD: Makefile,v 1.5 2012/07/02 13:37:36 adam Exp $
#

DISTNAME=	LibreCAD-LibreCAD-v1.0.0-0-g22839a7
PKGNAME=	librecad-1.0.0
PKGREVISION=	4
CATEGORIES=	cad
MASTER_SITES=	-https://github.com/LibreCAD/LibreCAD/zipball/v1.0.0
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://librecad.org/
COMMENT=	Free Open Source personal CAD application
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

# Force using "curl" for fetching the distribution file. It is only available
# over HTTPS and "curl" is the only fetch program which always supports HTTPS.
FETCH_USING=	curl

WRKSRC=		${WRKDIR}/LibreCAD-LibreCAD-2d7f866
USE_LANGUAGES=	c c++
USE_TOOLS+=	pax

REPLACE_SH=	scripts/postprocess-unix.sh

SUBST_CLASSES+=		qtdir
SUBST_STAGE.qtdir=	pre-configure
SUBST_MESSAGE.qtdir=	Set qt4/bin
SUBST_FILES.qtdir+=	scripts/postprocess-unix.sh
SUBST_VARS.qtdir+=	QTDIR

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Fix hardcoded path
SUBST_FILES.prefix+=	src/lib/engine/rs_system.cpp
SUBST_SED.prefix+=	-e 's,/usr/share/,${PREFIX}/share/,g'

LIBRECADDIR=		share/librecad

INSTALLATION_DIRS+=	bin ${LIBRECADDIR}

do-configure:
	 cd ${WRKSRC} && QTDIR=${QTDIR} ${QTDIR}/bin/qmake librecad.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unix/librecad \
		${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC}/unix/resources && \
		pax -rw -pmp fonts library patterns qm \
		${DESTDIR}${PREFIX}/${LIBRECADDIR}

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt4-tools=	full
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
