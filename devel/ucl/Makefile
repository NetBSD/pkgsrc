# $NetBSD: Makefile,v 1.18 2010/01/16 17:57:38 wiz Exp $
#

DISTNAME=	ucl-1.03
PKGREVISION=	1
CATEGORIES=	devel archivers
MASTER_SITES=	http://www.oberhumer.com/opensource/ucl/download/

MAINTAINER=	cjep@NetBSD.org
HOMEPAGE=	http://www.oberhumer.com/opensource/ucl/
COMMENT=	Portable lossless data compression library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--enable-shared=yes

# Avoid path to build directory in example Makefile
SUBST_CLASSES+=		example
SUBST_STAGE.example=	post-patch
SUBST_FILES.example=	examples/Makefile.in
SUBST_SED.example=	-e "s|@MAKEINFO@||g"

INSTALLATION_DIRS=	bin share/examples/ucl

post-install:
	for i in simple.c lutil.h uclpack.c; do		\
	${INSTALL_DATA} ${WRKSRC}/examples/$$i ${PREFIX}/share/examples/ucl;\
		done;
	cd ${WRKSRC}/examples && libtool --mode=install ${INSTALL_PROGRAM} uclpack ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
