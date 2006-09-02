# $NetBSD: Makefile,v 1.44 2006/09/02 08:38:07 rillig Exp $

DISTNAME=	jade-1.2.1
PKGREVISION=	11
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.jclark.com/pub/jade/ \
		ftp://ftp.funet.fi/pub/mirrors/ftp.jclark.com/pub/jade/ \
		ftp://ftp.u-aizu.ac.jp/pub/lang/sgml/jade/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.jclark.com/jade/
COMMENT=	Object-oriented SGML/XML parser toolkit and DSSSL engine

PATCH_SITES=		${MASTER_SITE_LOCAL}
PATCHFILES=		jade_1.2.1-18.diff.gz
PATCH_DIST_STRIP=	-p1

CONFLICTS+=	sp-[0-9]*

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

SGML_CATALOGS=		${PREFIX}/share/sgml/jade/catalog

CONFIGURE_ARGS+=	--enable-default-catalog=${PREFIX:Q}/share/sgml/jade/catalog
CONFIGURE_ARGS+=	--enable-mif

CXXFLAGS+=		${CFLAGS}

post-patch:
	chmod -R +w ${WRKSRC}
	find ${WRKSRC} -name '*.orig' -size 0c -type f -exec rm {} \;
	find ${WRKSRC} -name '*.orig_dist' -size 0c -type f -exec rm {} \;

post-install:
	set -e;								\
	for prog in jade nsgmls sgmlnorm spam spent sx; do		\
		${ECHO_MSG} "strip ${PREFIX}/bin/$${prog}";		\
		strip "${PREFIX}/bin/$${prog}";				\
	done
	${INSTALL_DATA_DIR} ${PREFIX}/include/sp
	${INSTALL_DATA} ${WRKSRC}/include/*.cxx ${WRKSRC}/include/*.h \
	  ${PREFIX}/include/sp
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/jade
	${INSTALL_DATA} ${WRKSRC}/jadedoc/*.htm ${PREFIX}/share/doc/jade
	${INSTALL_DATA_DIR} ${PREFIX}/share/sgml/jade
	${INSTALL_DATA} ${WRKSRC}/dsssl/* ${PREFIX}/share/sgml/jade
# Installed by print/tex-jadetex
	rm ${PREFIX}/share/sgml/jade/*jadetex.*

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"

# Turn off C++ optimization as there seem to be problems with the generated
# code: jade dumps core on some files if compiled with -O2.  This might be
# a compiler bug, or something deep inside the code...
#
# This is placed after the inclusion of bsd.pkg.mk to force this option to
# be the last optimization flag specified.
#
CXXFLAGS+=		-O0
