# $NetBSD: Makefile,v 1.48 2013/11/30 11:14:10 richard Exp $

DISTNAME=	zlib-1.2.8
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libpng/} \
		http://zlib.net/
DISTFILES=	# empty

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.zlib.net/
COMMENT=	General purpose data compression library
LICENSE=	zlib

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE+=	zlib.pc.in

CFLAGS+=		${CPPFLAGS}
LDFLAGS.Cygwin=		-no-undefined

SUBST_CLASSES+= pc
SUBST_MESSAGE.pc= pkg-config file substitutions
SUBST_STAGE.pc= pre-configure
SUBST_FILES.pc= zlib.pc.in
SUBST_SED.pc=	-e "s,@prefix@,${PREFIX},g"
SUBST_SED.pc+=	-e "s,@exec_prefix@,${PREFIX},g"
SUBST_SED.pc+=	-e "s,@VERSION@,${PKGVERSION_NOREV},g"
SUBST_SED.pc+=	-e "s,@includedir@,${PREFIX}/include,g"
SUBST_SED.pc+=	-e "s,@libdir@,${PREFIX}/lib,g"
SUBST_SED.pc+=	-e "s,@sharedlibdir@,${PREFIX}/lib,g"

INSTALLATION_DIRS=	include lib/pkgconfig ${PKGMANDIR}/man3

do-extract:
	${CP} -r ${FILESDIR} ${WRKSRC}

do-install:
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/libz.la ${DESTDIR}${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/zlib.3 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man3
	${INSTALL_DATA} ${WRKSRC}/zconf.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/zlib.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/zlib.pc.in ${DESTDIR}${PREFIX}/lib/pkgconfig/zlib.pc

.include "../../mk/bsd.pkg.mk"
