# $NetBSD: Makefile,v 1.25 2001/01/11 07:39:41 tron Exp $
#

DISTNAME=       mpg123-0.59r
CATEGORIES=	audio
MASTER_SITES=	http://www.mpg123.de/mpg123/ \
		http://www-ti.informatik.uni-tuebingen.de/~hippm/mpg123/

PATCH_SITES=	ftp://ftp.kame.net/pub/kame/misc/ \
		http://www.unix-ag.org/Linux-Alpha/Packages/
PATCHFILES=	mpg123-059r-v6-20000713b.diff.gz l3.diff.gz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.mpg123.de/

BUILD_DEFS+=	USE_INET6
DIST_SUBDIR=	mpg123

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
ALL_TARGET=	solaris-gcc
.endif

.if defined(USE_INET6) && ${USE_INET6} == "YES"
MAKE_ENV+=	CPPFLAGS="-DINET6"
.endif

MAKE_FLAGS+=	PREFIX="${PREFIX}"

pre-patch:
	${LN} -s . ${WRKSRC}/mpg123

post-patch:
	${RM} -f ${WRKSRC}/mpg123
	${CP} ${FILESDIR}/decode_i586_.s ${WRKSRC}/
	cd ${WRKSRC} ; ${MV} decode_i586.s decode_i586.s.orig ;\
	${SED} \
		-e 's@^/@#/@g' \
		<decode_i586.s.orig >decode_i586.s

.include "../../mk/bsd.pkg.mk"
