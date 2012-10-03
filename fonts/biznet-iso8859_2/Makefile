# $NetBSD: Makefile,v 1.16 2012/10/03 18:28:17 asau Exp $
#

DISTNAME=	ISO8859-2-pcf
PKGNAME=	biznet-iso8859_2-1.0
PKGREVISION=	4
CATEGORIES=	fonts x11
MASTER_SITES=	http://ultra.cto.us.edu.pl/pub/Unix/Fonts/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://web.archive.org/web/20041204153923/http://www.biz.net.pl/english/x-fonts/index.html
COMMENT=	Full set of ISO 8859-2 fonts for X Window System

USE_X11BASE=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

USE_TOOLS+=	gzip

FONTDIR=	${PREFIX}/lib/X11/fonts/biznet
REQD_DIRS=	${FONTDIR} ${FONTDIR}/75dpi ${FONTDIR}/100dpi ${FONTDIR}/misc
FONTS_DIRS.x11=	${FONTDIR}/75dpi ${FONTDIR}/100dpi ${FONTDIR}/misc

do-install:
	@for d in 75dpi 100dpi misc; do \
		${INSTALL_DATA_DIR} ${DESTDIR}${FONTDIR}/$${d}; \
		cd ${WRKDIR}/$${d}; \
		${INSTALL_DATA} fonts.alias ${DESTDIR}${FONTDIR}/$${d}/; \
		for f in *.pcf; do \
			${ECHO} "Compressing $${f}"; \
			${GZIP_CMD} -c $${f} > ${DESTDIR}${FONTDIR}/$${d}/$${f}.gz; \
		done; \
	done

.include "../../mk/bsd.pkg.mk"
