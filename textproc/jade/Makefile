# $NetBSD: Makefile,v 1.15 2001/10/05 10:02:53 tron Exp $
# FreeBSD Id: Makefile,v 1.15 1999/01/31 11:15:57 dirk Exp
#

DISTNAME=	jade-1.2.1
PKGNAME=	jade-1.2.1nb3
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.jclark.com/pub/jade/ \
		ftp://ftp.funet.fi/pub/mirrors/ftp.jclark.com/pub/jade/ \
		ftp://ftp.uni-trier.de/pub/languages/sgml/jade/ \
		ftp://ftp.u-aizu.ac.jp/pub/lang/sgml/jade/

MAINTAINER=	rh@NetBSD.ORG
HOMEPAGE=	http://www.jclark.com/jade/
COMMENT=	Object-oriented SGML/XML parser toolkit and DSSSL engine

CONFLICTS+=	sp-[0-9]*

USE_BUILDLINK_ONLY=	yes
GNU_CONFIGURE=		yes
#USE_LIBINTL=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/config/ltconfig

JADE_CATALOG_DIR=	${PREFIX}/share/sgml/jade/catalog

CONFIGURE_ARGS=		--disable-shared
CONFIGURE_ARGS+=	--enable-default-catalog=${JADE_CATALOG_DIR}
CONFIGURE_ARGS+=	--enable-mif

CXXFLAGS+=		${CFLAGS}

post-install:
	@for prog in jade nsgmls sgmlnorm spam spent sx; do		\
		${ECHO_MSG} "strip ${PREFIX}/bin/$${prog}";		\
		strip ${PREFIX}/bin/$${prog};				\
	done
	${INSTALL_DATA_DIR} ${PREFIX}/include/sp
	${INSTALL_DATA} ${WRKSRC}/include/* ${PREFIX}/include/sp
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/jade
	${INSTALL_DATA} ${WRKSRC}/jadedoc/*.htm ${PREFIX}/share/doc/jade
	${INSTALL_DATA_DIR} ${PREFIX}/share/sgml/jade
	${RM} ${WRKSRC}/dsssl/*jadetex.*	# installed by print/tex-jadetex!!!
	${INSTALL_DATA} ${WRKSRC}/dsssl/* ${PREFIX}/share/sgml/jade

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
