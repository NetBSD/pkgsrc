# $NetBSD: Makefile,v 1.12 2016/02/25 08:27:03 jperkin Exp $

.include "../../x11/qt5/Makefile.common"

DISTNAME=	uim-1.8.6
PKGNAME=	qt5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	x11
MASTER_SITES=	http://uim.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2
DISTFILES=	${DEFAULT_DISTFILES} uim-1.8.7pre1.tar.gz
SITES.uim-1.8.7pre1.tar.gz=	${MASTER_SITE_LOCAL}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://code.google.com/p/uim/
COMMENT=	Qt5 input module for uim
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake gsed intltool pkg-config xgettext
BUILDLINK_DEPMETHOD.gtk2=	build

USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	uim.pc.in

CONFIGURE_ENV+=		QMAKE5=${QTPREFIX}/bin/qmake
CONFIGURE_ENV.SunOS+=	ac_cv_func_strcasecmp=yes

CONFIGURE_ARGS+=	--with-qt5-immodule
CONFIGURE_ARGS+=	--disable-emacs
CONFIGURE_ARGS+=	--with-libgcroots=installed

INSTALL_DIRS+=		qt5

post-extract:
	cd ${WRKSRC} && \
		${CP} -r ../uim-1.8.7pre1/qt5 .
	cd ${WRKSRC} && \
		${RM} -fr qt4 &&\
		${CP} -r ../uim-1.8.7pre1/qt4 .
	cd ${WRKSRC} && \
		${CP} ../uim-1.8.7pre1/configure .

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgcroots/buildlink3.mk"
.include "../../inputmethod/uim/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
