# $NetBSD: Makefile,v 1.1 2002/06/22 17:56:38 kent Exp $

DISTNAME=	mpg123-0.59r
PKGNAME=	mpg123-esound-0.59.18
CATEGORIES=	audio
MASTER_SITES=	http://www.mpg123.de/mpg123/ \
		http://www-ti.informatik.uni-tuebingen.de/~hippm/mpg123/

PATCH_SITES=	ftp://ftp.kame.net/pub/kame/misc/
PATCHFILES=	mpg123-059r-v6-20000713b.diff.gz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.mpg123.de/
COMMENT=	Command-line player for mpeg layer 1, 2 and 3 audio with EsounD

BUILD_DEFS+=	USE_INET6
DIST_SUBDIR=	mpg123

PATCHDIR=	../mpg123/patches
FILESDIR=	../mpg123/files

USE_BUILDLINK_ONLY=	# defined

# for OBJECT_FMT
.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "i386")
.if (${OBJECT_FMT} == "ELF")
ALL_TARGET=	netbsd-i386-elf-esd
.else
ALL_TARGET=	netbsd-i386-esd
.endif
.elif (${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32")
ALL_TARGET=	netbsd-arm-esd
.elif (${MACHINE_ARCH} == "m68k")
ALL_TARGET=	netbsd-m68k-esd
.else
ALL_TARGET=	${LOWER_OPSYS}-esd
.endif

.if ${OPSYS} == "SunOS"
ALL_TARGET=	solaris-gcc-esd
.endif

.if defined(USE_INET6) && ${USE_INET6} == "YES"
CPPFLAGS+=	-DINET6
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

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mpg123 ${PREFIX}/bin/mpg123-esound

.include "../esound/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
