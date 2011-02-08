# $NetBSD: Makefile,v 1.1.1.1 2011/02/08 18:32:23 drochner Exp $
#

DISTNAME=	gps-${GPS_VERSION}
CATEGORIES=	devel
MASTER_SITES=	http://downloads.dragonlace.net/src/ \
		http://dragonlace.mirrors.ada.cx/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	draco@marino.st
HOMEPAGE=	http://www.adacore.com/home/products/gnatpro/toolsuite/gps/
COMMENT=	GNAT Programming Studio - IDE for Ada and many other languages
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake sed perl awk

GPS_VERSION=		5.0.0
FULL_PATH=		/sbin:/bin:/usr/sbin:/usr/bin:${PREFIX}/sbin:${PREFIX}/bin:${PREFIX}/lib/pkgconfig
MY_CONFIGURE_ENV=	PATH=${FULL_PATH}
MY_CONFIGURE_ENV+=	CC=gnatgcc
APP=			${PREFIX}/lib/gnat
TPLS=			${PREFIX}/share/gps/templates

.include "options.mk"

# Do to hardcoding on GPS' part, can't get python to work yet
CONFIGURE_ARGS+=	--with-gmp=${PREFIX}
CONFIGURE_ARGS+=	--with-python=no
CONFIGURE_ARGS+=	--enable-shared-python=yes

do-wrapper:
	# Disable problematic wrappers
	@${ECHO} "###  Pkgsrc wrappers disabled  ###"

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MY_CONFIGURE_ENV} ./configure ${CONFIGURE_ARGS}
do-build:
	cd ${WRKSRC} && ${SETENV} ADA_PROJECT_PATH=${APP} gmake default

# "scripts" directory does not exist, tests disable
#do-test:
#	cd ${WRKSRC}/scripts && ./testsuites
#test-clean:
#	cd ${WRKSRC}/scripts && ./testsuites clean

post-install:
	${TOUCH} ${DESTDIR}${PREFIX}/share/doc/gps/pdf/IGNORE.ME
	${TOUCH} ${DESTDIR}${PREFIX}/share/doc/gps/txt/IGNORE.ME
	${TOUCH} ${DESTDIR}${PREFIX}/share/examples/gps/tutorial/matrix_handling/IGNORE.ME
	${TOUCH} ${DESTDIR}${TPLS}/ajis_hello/obj/IGNORE.ME
	${TOUCH} ${DESTDIR}${TPLS}/ajis_hello/bin/IGNORE.ME
	${TOUCH} ${DESTDIR}${TPLS}/ajis_hello/binding/IGNORE.ME
	${TOUCH} ${DESTDIR}${TPLS}/gtkada_minimal/obj/IGNORE.ME
	${TOUCH} ${DESTDIR}${TPLS}/simple_project/obj/IGNORE.ME
	${STRIP} ${DESTDIR}${PREFIX}/bin/gps

.include "../../x11/gtkada/buildlink3.mk"
.include "../../textproc/xmlada/buildlink3.mk"
.include "../../devel/gprbuild-aux/buildlink3.mk"
#.include "../../lang/python26/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
