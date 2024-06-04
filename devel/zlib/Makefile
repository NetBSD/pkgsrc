# $NetBSD: Makefile,v 1.64 2024/06/04 18:33:45 bsiegert Exp $

DISTNAME=	zlib-1.3.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libpng/}
MASTER_SITES+=	http://zlib.net/
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.zlib.net/
COMMENT=	General purpose data compression library
LICENSE=	zlib

USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	zlib.pc.in

CFLAGS+=		${CPPFLAGS}
LDFLAGS.Cygwin=		-no-undefined

.include "../../mk/bsd.prefs.mk"
.if ${MACHINE_ARCH} == i386
# use NO_DIVIDE for adler32 if processor does not do division in hardware
# which avoids needing emulation provided by libgcc_s
CPPFLAGS.SunOS+=	-DNO_DIVIDE
.endif
LDFLAGS.SunOS+=	-Wl,-zignore	# avoid unused reference to libgcc_s.so

CFLAGS.Linux+=	-DZ_HAVE_UNISTD_H
LDFLAGS.Linux+=	-Wl,--version-script,zlib.map

SUBST_CLASSES+=		pc
SUBST_MESSAGE.pc=	pkg-config file substitutions
SUBST_STAGE.pc=		pre-configure
SUBST_FILES.pc=		zlib.pc.in
SUBST_SED.pc=		-e "s,@prefix@,${PREFIX},g"
SUBST_SED.pc+=		-e "s,@exec_prefix@,${PREFIX},g"
SUBST_SED.pc+=		-e "s,@VERSION@,${PKGVERSION_NOREV},g"
SUBST_SED.pc+=		-e "s,@includedir@,${PREFIX}/include,g"
SUBST_SED.pc+=		-e "s,@libdir@,${PREFIX}/lib,g"
SUBST_SED.pc+=		-e "s,@sharedlibdir@,${PREFIX}/lib,g"

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
