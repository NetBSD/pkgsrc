# $NetBSD: Makefile,v 1.19 1999/07/12 04:34:23 windsor Exp $
# FreeBSD Id: Makefile,v 1.20 1997/08/27 13:06:01 ache Exp
#

DISTNAME=	pgp263is
WRKSRC=		${WRKDIR}/src
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.ifi.uio.no/pub/pgp/2.x/src/ \
		ftp://ftp.kiarchive.ru/pub/unix/crypto/pgp/

MAINTAINER=	packages@NetBSD.ORG
HOMEPAGE=	http://www.pgpi.com/

.include "../../mk/bsd.prefs.mk"

.if defined(USE_RSAREF2) && ${USE_RSAREF2} == YES
PKGNAME=	pgp-2.6.3a
DEPENDS+=	rsaref-2.0p2:../../security/rsaref
RSAINC=		-I${PREFIX}/include
RSALIBS=	-Wl,-R${PREFIX}/lib -L${PREFIX}/lib -lrsaref
RSAOBJS=	rsaglue2.o
CFLAGS=		-DUSA
.else
PKGNAME=	pgp-2.6.3ia
RSAINC=
RSALIBS=
RSAOBJS=	rsaglue1.o
CFLAGS=
.endif

RESTRICTED=	"Cryptographic software"
MIRROR_DISTFILE=no
PGPLIB=		${PREFIX}/share/pgp
CFLAGS+=	-DPGP_SYSTEM_DIR=\\\"${PGPLIB}/\\\"
IS_INTERACTIVE=	yes

.if ${MACHINE_ARCH} == "i386"
OBJS_EXT=	_80386.o _zmatch.o
ASMFLAG=	-DASM
.elif ${MACHINE_ARCH} == "m68k"
.ifdef M68060
OBJS_EXT=
ASMFLAG=	-m68060 -DPORTABLE -DMPORTABLE
.else
OBJS_EXT=	mc68020.o
ASMFLAG=
.endif
.elif ${MACHINE_ARCH} == "sparc"
OBJS_EXT=	sparc.o
ASMFLAG=
.else
OBJS_EXT=
ASMFLAG=	-DPORTABLE -DMPORTABLE
.endif

.if !defined(USE_RSAREF2) || ${USE_RSAREF2} != YES && ${USE_RSAREF2} != NO
pre-fetch:
	@${ECHO}
	@${ECHO} The variable USE_RSAREF2 must be set to either YES or NO
	@${ECHO} in order to build this package.  USA residents that are
	@${ECHO} no licensees of the RSA algorithm MUST set this variable
	@${ECHO} to YES.  Users outside the USA MUST set this variable to
	@${ECHO} NO.  Licensees may choose -- NO is faster.
	@${FALSE}
.endif

post-extract:
	cd ${WRKDIR} && ${GTAR} xf pgp263ii.tar && ${RM} -f pgp263ii.tar

do-build:
	cd ${WRKSRC} && ${MAKE} all CC=${CC} LD=${CC} OBJS_EXT="${OBJS_EXT}" \
		CFLAGS="${CFLAGS} ${RSAINC} ${ASMFLAG} -O2 -DUNIX -DIDEA32 \
		-DMAX_NAMELEN=255" RSALIBS="${RSALIBS}" RSAOBJS="${RSAOBJS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pgp ${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/doc/pgp.1 ${PREFIX}/man/man1
	-${MKDIR} ${PGPLIB}
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
