# $NetBSD: Makefile,v 1.14 2005/06/24 10:55:20 kristerw Exp $
#

DISTNAME=	ucl-1.02
PKGREVISION=	3
CATEGORIES=	devel archivers
MASTER_SITES=	http://www.oberhumer.com/opensource/ucl/download/

MAINTAINER=	cjep@NetBSD.org
HOMEPAGE=	http://www.oberhumer.com/opensource/ucl/
COMMENT=	Portable lossless data compression library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--enable-shared=yes

# Avoid an ICE in gcc2 on sparc64
CONFIGURE_ENV+=	F77=${FALSE}

# Avoid path to build directory in example Makefile
SUBST_CLASSES=		example
SUBST_STAGE.example=	post-patch
SUBST_FILES.example=	examples/Makefile.in
SUBST_SED.example=	-e "s|@MAKEINFO@||g"

INSTALLATION_DIRS=	bin

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ucl
	for i in simple.c lutil.h uclpack.c Makefile; do		\
	${INSTALL_DATA} ${WRKSRC}/examples/$$i ${PREFIX}/share/examples/ucl;\
		done;
	cd ${WRKSRC}/examples && libtool --mode=install ${INSTALL_PROGRAM} uclpack ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
