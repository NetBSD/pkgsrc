# $NetBSD: Makefile,v 1.26 2001/02/06 03:16:58 fredb Exp $
#

DISTNAME=		giflib-4.1.0
CATEGORIES=		graphics
MASTER_SITES=		ftp://prtr-13.ucsc.edu/pub/libungif/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://prtr-13.ucsc.edu/~badger/software/libungif/index.shtml

CONFLICTS=		libungif-*

BUILD_DEPENDS+=		${LOCALBASE}/bin/autoreconf:../../devel/autoconf

USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS=		--without-x

DOCDIR=			${PREFIX}/share/doc/giflib
HTMLDIR=		${PREFIX}/share/doc/html/giflib

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=		CC="${CC} -I${LOCALBASE}/include"
.endif

post-patch:
	${RM} ${WRKSRC}/doc/gif2x11.html

pre-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/autoreconf

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} COPYING PATENT_PROBLEMS ${DOCDIR}
	${INSTALL_DATA_DIR} ${HTMLDIR}
	cd ${WRKSRC}/doc; ${INSTALL_DATA} *.html *.txt *.png ${HTMLDIR}

.include "../../mk/bsd.pkg.mk"
