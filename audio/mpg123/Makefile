# $NetBSD: Makefile,v 1.15 1999/07/10 10:39:02 tron Exp $
#

DISTNAME=       mpg123-0.59r
CATEGORIES=	audio
MASTER_SITES=	http://www-ti.informatik.uni-tuebingen.de/~hippm/mpg123/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www-ti.informatik.uni-tuebingen.de/~hippm/mpg123.html

# for OBJECT_FMT
.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "i386")
.if (${OBJECT_FMT} == "ELF")
ALL_TARGET=	netbsd-i386-elf
.else
ALL_TARGET=	netbsd-i386
.endif
.elif (${MACHINE_ARCH} == "m68k")
ALL_TARGET=	netbsd-m68k
.else
ALL_TARGET=	netbsd
.endif

MAKE_FLAGS+=	PREFIX="${PREFIX}"

post-patch:
	${CP} ${FILESDIR}/decode_i586_.s ${WRKSRC}/
	cd ${WRKSRC} ; ${MV} decode_i586.s decode_i586.s.orig ;\
	${SED} \
		-e 's@^/@#/@g' \
		<decode_i586.s.orig >decode_i586.s

.include "../../mk/bsd.pkg.mk"
