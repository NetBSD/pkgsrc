# $NetBSD: Makefile,v 1.46 2005/12/01 20:17:48 wiz Exp $

DISTNAME=	pgp263is
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.ifi.uio.no/pub/pgp/2.x/src/ \
		ftp://ftp.kiarchive.ru/pub/unix/crypto/pgp/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.pgpi.com/
COMMENT=	Public-key encryption and digital signature utility (v2)

WRKSRC=		${WRKDIR}/src
CRYPTO=		yes

# use of IDEA as crypto function
LICENCE=	fee-based-commercial-use

.include "options.mk"

.include "../../mk/bsd.prefs.mk"

PGPLIB=		${PREFIX}/share/pgp
CFLAGS+=	-DPGP_SYSTEM_DIR="\"${PGPLIB}/\""

.if (${MACHINE_ARCH} == "i386")
OBJS_EXT=	_80386.o _zmatch.o
ASMFLAG=	-DASM
.elif (${MACHINE_ARCH} == "sparc") && (${OPSYS} != SunOS)
OBJS_EXT=	sparc.o
ASMFLAG=
.else
OBJS_EXT=
ASMFLAG=	-DPORTABLE -DMPORTABLE
.endif

.include "../../mk/endian.mk"

.if (${MACHINE_ENDIAN} == "big")
CFLAGS+=        -DHIGHFIRST
.endif

BUILD_DEFS+=	ASMFLAG

INSTALLATION_DIRS=	bin man/man1

post-extract:
	cd ${WRKDIR} && ${TAR} xf pgp263ii.tar && ${RM} -f pgp263ii.tar

do-build:
	cd ${WRKSRC} && ${MAKE} all CC="${CC}" LD="${CC}" \
		OBJS_EXT="${OBJS_EXT}" \
		CFLAGS=${CFLAGS:Q}" ${RSAINC} ${ASMFLAG} -O2 -DUNIX -DIDEA32 \
		-DMAX_NAMELEN=255" RSALIBS="${RSALIBS}" RSAOBJS="${RSAOBJS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pgp ${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/doc/pgp.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PGPLIB}
	cd ${WRKDIR}/doc && ${INSTALL_DATA} pgpdoc1.txt pgpdoc2.txt ${PGPLIB}
	cd ${WRKDIR} && \
		${INSTALL_DATA} de.hlp en.hlp es.hlp fr.hlp pgp.hlp ${PGPLIB}
	[ -f ${PGPLIB}/language.txt ] || \
		${INSTALL_DATA} ${WRKDIR}/language.txt ${PGPLIB}
	[ -f ${PGPLIB}/config.txt ] || \
		${INSTALL_DATA} ${WRKDIR}/config.txt ${PGPLIB}
	[ -f ${PGPLIB}/pgp.hlp ] || \
		${INSTALL_DATA} ${WRKDIR}/en.hlp ${PGPLIB}/pgp.hlp

.include "../../mk/bsd.pkg.mk"
