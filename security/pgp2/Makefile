# $NetBSD: Makefile,v 1.59 2020/03/18 18:00:48 joerg Exp $

DISTNAME=	pgp263is
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.ifi.uio.no/pub/pgp/2.x/src/
MASTER_SITES+=	ftp://ftp.kiarchive.ru/pub/unix/crypto/pgp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pgpi.org/
COMMENT=	Public-key encryption and digital signature utility (v2)
LICENSE=	pgp2-license

USE_TOOLS+=	tar
WRKSRC=		${WRKDIR}/src

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
CFLAGS+=	-DHIGHFIRST
.endif

BUILD_DEFS+=	ASMFLAG

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PGPLIB}

post-extract:
	cd ${WRKDIR} && ${TAR} xf pgp263ii.tar && ${RM} -f pgp263ii.tar

do-build:
	cd ${WRKSRC} && ${MAKE} all CC="${CC}" LD="${CC}" \
		OBJS_EXT="${OBJS_EXT}" \
		CFLAGS=${CFLAGS:Q}" ${RSAINC} ${ASMFLAG} -O2 -DUNIX -DIDEA32 \
		-DMAX_NAMELEN=255" RSALIBS="${RSALIBS}" RSAOBJS="${RSAOBJS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pgp ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/doc/pgp.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	cd ${WRKDIR}/doc && ${INSTALL_DATA} pgpdoc1.txt pgpdoc2.txt ${DESTDIR}${PGPLIB}
	cd ${WRKDIR} && \
		${INSTALL_DATA} de.hlp en.hlp es.hlp fr.hlp pgp.hlp ${DESTDIR}${PGPLIB}
	${INSTALL_DATA} ${WRKDIR}/language.txt ${DESTDIR}${PGPLIB}
	${INSTALL_DATA} ${WRKDIR}/config.txt ${DESTDIR}${PGPLIB}
	${INSTALL_DATA} ${WRKDIR}/en.hlp ${DESTDIR}${PGPLIB}/pgp.hlp

.include "../../mk/bsd.pkg.mk"
