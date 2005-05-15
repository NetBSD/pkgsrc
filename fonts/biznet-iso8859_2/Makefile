# $NetBSD: Makefile,v 1.5 2005/05/15 22:02:26 jlam Exp $
#

DISTNAME=	ISO8859-2-pcf
PKGNAME=	biznet-iso8859_2-1.0
CATEGORIES=	fonts x11
MASTER_SITES=	http://www.biz.net.pl/images/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.biz.net.pl/english/x-fonts/index.html
COMMENT=	Full set of ISO 8859-2 fonts for X Window System

USE_X11BASE=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

PKGSRC_USE_TOOLS+=	gzip

FONTDIR=	${PREFIX}/lib/X11/fonts/biznet
OWN_DIRS=	${FONTDIR}
FONTS_X11_DIRS=	${FONTDIR}/75dpi ${FONTDIR}/100dpi ${FONTDIR}/misc

do-install:
	@for d in 75dpi 100dpi misc; do \
		${INSTALL_DATA_DIR} ${FONTDIR}/$${d}; \
		cd ${WRKDIR}/$${d}; \
		${INSTALL_DATA} fonts.alias ${FONTDIR}/$${d}/; \
		for f in *.pcf; do \
			${ECHO} "Compressing $${f}"; \
			${GZIP_CMD} -c $${f} > ${FONTDIR}/$${d}/$${f}.gz; \
		done; \
	done

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
