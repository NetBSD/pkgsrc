# $NetBSD: Makefile,v 1.9 2012/09/15 10:03:48 obache Exp $
#

DISTNAME=	LibreCAD-LibreCAD-v1.0.2-0-ga6826ad
PKGNAME=	librecad-1.0.2
PKGREVISION=	3
CATEGORIES=	cad
MASTER_SITES=	-https://github.com/LibreCAD/LibreCAD/tarball/v1.0.2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://librecad.org/
COMMENT=	Free Open Source personal CAD application
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

# Force using "curl" for fetching the distribution file. It is only available
# over HTTPS and "curl" is the only fetch program which always supports HTTPS.
FETCH_USING=	curl

WRKSRC=		${WRKDIR}/LibreCAD-LibreCAD-a5c34b2
USE_LANGUAGES=	c c++
USE_TOOLS+=	bash pax

REPLACE_BASH=	scripts/postprocess-unix.sh

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
.include "../../math/muparser/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt4-tools=	full
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
