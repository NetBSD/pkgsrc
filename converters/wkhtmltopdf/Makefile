# $NetBSD: Makefile,v 1.4 2018/08/22 09:43:09 wiz Exp $

DISTNAME=       wkhtmltox-0.12.4
PKGNAME=	wkhtmltopdf-0.12.4
PKGREVISION=	2
MASTER_SITES=   ${MASTER_SITE_GITHUB:=wkhtmltopdf/}
GITHUB_PROJECT= wkhtmltopdf
GITHUB_RELEASE= ${PKGVERSION_NOREV}
EXTRACT_SUFX=   .tar.bz2

CATEGORIES=	www print converters
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wkhtmltopdf.org/
COMMENT=	Command line tools to render HTML into PDF
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES+=	c c++ gnu++98
USE_TOOLS+=	perl
#USE_LIBTOOL=	yes

BUILDLINK_TRANSFORM+=   opt:-std=gnu++11:-std=gnu++98 

SUBST_CLASSES+=		x11
SUBST_MESSAGE.x11=	Fixing x11 options.
SUBST_STAGE.x11=	pre-configure
SUBST_FILES.x11+=	qt/mkspecs/netbsd-g++/qmake.conf
SUBST_SED.x11=		-e 's,@X11BASE@,${X11BASE},g'


do-configure:
	for f in `find ${WRKSRC} -type f -name '*.py' -print`; do 	\
		cp $$f $$f.orig &&					\
		sed '1s|^#!.*$$|#!${PYTHONBIN}|' $$f.orig > $$f;	\
	done

do-build:
	cd ${WRKSRC} && \
	${PKGSRC_SETENV} ${MAKE_ENV}  ${PYTHONBIN} scripts/build.py posix-local -debug

WKHTMLTOX_BUILD=${WRKSRC}/static-build/posix-local-dbg/${DISTNAME}
WKHTMLTOX_BIN=${DESTDIR}${PREFIX}/bin
WKHTMLTOX_DATA=${DESTDIR}${PREFIX}/include/wkhtmltox
WKHTMLTOX_LIB=${DESTDIR}${PREFIX}/lib
do-install:
	${INSTALL_PROGRAM_DIR} ${WKHTMLTOX_BIN}
.for b in bin/wkhtmltoimage bin/wkhtmltopdf
	${INSTALL_PROGRAM} ${WKHTMLTOX_BUILD}/${b} ${WKHTMLTOX_BIN}
.endfor
	${INSTALL_DATA_DIR} ${WKHTMLTOX_DATA}
.for h in include/wkhtmltox/image.h include/wkhtmltox/pdf.h
	${INSTALL_DATA} ${WKHTMLTOX_BUILD}/${h} ${WKHTMLTOX_DATA}
.endfor
	${INSTALL_LIB_DIR} ${WKHTMLTOX_LIB}
.for l in lib/libwkhtmltox.so.0.12.4
	${INSTALL_LIB} ${WKHTMLTOX_BUILD}/${l} ${WKHTMLTOX_LIB}
.endfor
	cd ${WKHTMLTOX_LIB} && 					\
	    ln -sf libwkhtmltox.so.0.12.4 libwkhtmltox.so.0.1 && \
	    ln -sf libwkhtmltox.so.0.12.4 libwkhtmltox.so.0

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
