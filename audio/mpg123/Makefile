# $NetBSD: Makefile,v 1.19 2000/02/18 11:04:10 itojun Exp $
#

DISTNAME=       mpg123-0.59r
CATEGORIES=	audio
MASTER_SITES=	http://www.mpg123.de/mpg123/ \
		http://www-ti.informatik.uni-tuebingen.de/~hippm/mpg123/

PATCH_SITES=	ftp://ftp.kame.net/pub/kame/misc/
PATCHFILES=	mpg123-059r-v6-20000111.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.mpg123.de/

BUILD_DEFS+=	USE_INET6

# for OBJECT_FMT
.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "i386")
.if (${OBJECT_FMT} == "ELF")
ALL_TARGET=	netbsd-i386-elf
.else
ALL_TARGET=	netbsd-i386
.endif
.elif (${MACHINE_ARCH} == "arm32")
ALL_TARGET=	netbsd-arm32
.elif (${MACHINE_ARCH} == "m68k")
ALL_TARGET=	netbsd-m68k
.else
ALL_TARGET=	${LOWER_OPSYS}
.endif

.if ${OPSYS} == "SunOS"
MAKE_ENV+=	CPPFLAGS=""
.endif

.if defined(USE_INET6) && ${USE_INET6} == "YES"
MAKE_ENV+=	CPPFLAGS="-DINET6"
.endif

MAKE_FLAGS+=	PREFIX="${PREFIX}"

post-patch:
	${CP} ${FILESDIR}/decode_i586_.s ${WRKSRC}/
	cd ${WRKSRC} ; ${MV} decode_i586.s decode_i586.s.orig ;\
	${SED} \
		-e 's@^/@#/@g' \
		<decode_i586.s.orig >decode_i586.s

.include "../../mk/bsd.pkg.mk"
