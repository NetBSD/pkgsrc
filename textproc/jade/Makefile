# $NetBSD: Makefile,v 1.18 2001/11/29 01:12:49 hubertf Exp $

DISTNAME=	jade-1.2.1
PKGREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.jclark.com/pub/jade/ \
		ftp://ftp.funet.fi/pub/mirrors/ftp.jclark.com/pub/jade/ \
		ftp://ftp.uni-trier.de/pub/languages/sgml/jade/ \
		ftp://ftp.u-aizu.ac.jp/pub/lang/sgml/jade/

MAINTAINER=	rh@NetBSD.ORG
HOMEPAGE=	http://www.jclark.com/jade/
COMMENT=	Object-oriented SGML/XML parser toolkit and DSSSL engine

PATCH_SITES=		http://ftp.debian.org/debian/pool/main/j/jade/
PATCHFILES=		jade_1.2.1-18.diff.gz
PATCH_DIST_STRIP=	-p1

CONFLICTS+=	sp-[0-9]*

USE_BUILDLINK_ONLY=	YES
USE_GMAKE=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/config/ltconfig

JADE_CATALOG_DIR=	${PREFIX}/share/sgml/jade/catalog

CONFIGURE_ARGS=		--disable-shared
CONFIGURE_ARGS+=	--enable-default-catalog=${JADE_CATALOG_DIR}
CONFIGURE_ARGS+=	--enable-mif

CXXFLAGS+=		${CFLAGS}

post-patch:
	@${CHMOD} -R +w ${WRKSRC}
	@${FIND} ${WRKSRC} -name '*.orig' -size 0c -type f | ${XARGS} ${RM}

post-install:
	@for prog in jade nsgmls sgmlnorm spam spent sx; do		\
		${ECHO_MSG} "strip ${PREFIX}/bin/$${prog}";		\
		strip ${PREFIX}/bin/$${prog};				\
	done
	${INSTALL_DATA_DIR} ${PREFIX}/include/sp
	${INSTALL_DATA} ${WRKSRC}/include/*.cxx ${WRKSRC}/include/*.h \
	  ${PREFIX}/include/sp
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/jade
	${INSTALL_DATA} ${WRKSRC}/jadedoc/*.htm ${PREFIX}/share/doc/jade
	${INSTALL_DATA_DIR} ${PREFIX}/share/sgml/jade
	${INSTALL_DATA} ${WRKSRC}/dsssl/* ${PREFIX}/share/sgml/jade
# Installed by print/tex-jadetex
	${RM} ${PREFIX}/share/sgml/jade/*jadetex.*

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"

# Turn off C++ optimization as there seem to be problems with the generated
# code: jade dumps core on some files if compiled with -O2.  This might be
# a compiler bug, or something deep inside the code...
#
# This is placed after the inclusion of bsd.pkg.mk to force this option to
# be the last optimization flag specified.
#
CXXFLAGS+=		-O0
