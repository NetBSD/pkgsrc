# $NetBSD: Makefile,v 1.26 2004/01/05 20:38:35 jlam Exp $
#

DISTNAME=	libungif-4.1.0b1
PKGNAME=	libungif-4.1.0.1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.ayamura.org/pub/graphics/ \
		ftp://prtr-13.ucsc.edu/pub/libungif/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://prtr-13.ucsc.edu/~badger/software/libungif/index.shtml
COMMENT=	Tools and library routines for working with GIF images

CONFLICTS=	giflib-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--without-x

USE_BUILDLINK3=		yes

DOCDIR=			${PREFIX}/share/doc/libungif
HTMLDIR=		${PREFIX}/share/doc/html/libungif

REPLACE_PERL=		util/gifburst

post-patch:
	${RM} ${WRKSRC}/doc/gif2x11.html

post-install:
	cd ${PREFIX}; \
	for f in libungif.a libungif.so libungif.so.5 libungif.so.5.0; do \
		g=`echo $$f | ${SED} "s,libungif,libgif,"`; \
		${LN} -sf $$f ${PREFIX}/lib/$$g; \
	done
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} COPYING UNCOMPRESSED_GIF ${DOCDIR}
	${INSTALL_DATA_DIR} ${HTMLDIR}
	cd ${WRKSRC}/doc; ${INSTALL_DATA} *.html *.txt *.png ${HTMLDIR}

.include "../../mk/bsd.pkg.mk"
