# $NetBSD: Makefile,v 1.1.1.1 1999/10/09 20:05:39 jlam Exp $
#

DISTNAME=	libungif-4.1.0
CATEGORIES=	graphics
MASTER_SITES=	ftp://prtr-13.ucsc.edu/pub/libungif/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://prtr-13.ucsc.edu/~badger/software/libungif.shtml

CONFLICTS=	giflib-*

USE_LIBTOOL=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-x

DOCDIR=		${PREFIX}/share/doc/libungif

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=	CC="${CC} -I${LOCALBASE}/include"
.endif

post-patch:
	${RM} ${WRKSRC}/doc/gif2x11.html

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} COPYING UNCOMPRESSED_GIF ${DOCDIR}
	cd ${WRKSRC}/doc; ${INSTALL_DATA} *.html *.txt *.png ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
