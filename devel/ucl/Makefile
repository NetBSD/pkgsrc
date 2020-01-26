# $NetBSD: Makefile,v 1.26 2020/01/26 17:31:05 rillig Exp $
#

DISTNAME=	ucl-1.03
PKGREVISION=	1
CATEGORIES=	devel archivers
MASTER_SITES=	http://www.oberhumer.com/opensource/ucl/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.oberhumer.com/opensource/ucl/
COMMENT=	Portable lossless data compression library
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-shared=yes

# Avoid path to build directory in example Makefile
SUBST_CLASSES+=		example
SUBST_STAGE.example=	pre-configure
SUBST_FILES.example=	examples/Makefile.in
SUBST_SED.example=	-e "s|@MAKEINFO@||g"

INSTALLATION_DIRS=	bin share/examples/ucl

post-install:
	for i in simple.c lutil.h uclpack.c; do		\
	${INSTALL_DATA} ${WRKSRC}/examples/$$i ${DESTDIR}${PREFIX}/share/examples/ucl;\
		done;
	cd ${WRKSRC}/examples && libtool --mode=install ${INSTALL_PROGRAM} uclpack ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
