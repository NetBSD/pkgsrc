# $NetBSD: Makefile,v 1.1.1.1 1999/05/23 22:41:21 tv Exp $

DISTNAME=       hpack79${USE_RSAREF2:S/YES/u/:C/[^u]*//g}src
PKGNAME=        hpack-0.79
CATEGORIES=	archivers
MASTER_SITES=   ftp://src.doc.ic.ac.uk/packages/hpack/

MAINTAINER=     packages@netbsd.org

RESTRICTED=	crypto
MIRROR_DISTFILE=no

NO_WRKSUBDIR=	yes
PATCHDIR=	${WRKDIR}/.patches

MAKEFILE=       makefile
ALL_TARGET=     hpack
MAKE_FLAGS=	CFLAGS="-c -DBSD386 -D__UNIX__ -DPREFIX=\\\"${PREFIX}\\\" -I. ${CFLAGS} -Icrypt" \
		CMDL="${LDFLAGS} -ltermcap"

.include "../../mk/bsd.prefs.mk"
.if defined(USE_RSAREF2) && ${USE_RSAREF2} == YES
DEPENDS+=	rsaref-2.0p1:../../security/rsaref
LDFLAGS+=	-L${LOCALBASE}/lib -lrsaref
CFLAGS+=	-I${LOCALBASE}/include -DRSAREF
.endif

fetch-depends:
.if !defined(USE_RSAREF2) || ${USE_RSAREF2} != YES && ${USE_RSAREF2} != NO
	@${ECHO}
	@${ECHO} The variable USE_RSAREF2 must be set to either YES or NO
	@${ECHO} in order to build this package.  USA residents that are
	@${ECHO} not licensees of the RSA algorithm MUST set this variable
	@${ECHO} to YES.  Users outside the USA MUST set this variable to
	@${ECHO} NO.  Licensees may choose -- NO is faster.
	@${FALSE}
.endif

post-extract:
	@${MKDIR} ${PATCHDIR}
	@${CP} ${.CURDIR}/patches/patch-* ${PATCHDIR}/
.if defined(USE_RSAREF2) && ${USE_RSAREF2} == NO
	@${RM} -f ${PATCHDIR}/patch-rsaref
.endif

post-build:
	@cd ${WRKSRC}/keycvt && ${MAKE} CFLAGS="-c -D__UNIX__ ${CFLAGS}" \
		-f ${MAKEFILE} keycvt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hpack ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/keycvt/keycvt ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/docs/hpack.1 ${PREFIX}/man/man1/
	${INSTALL_DATA_DIR} ${PREFIX}/share/hpack ${PREFIX}/share/doc/hpack
	${INSTALL_DATA} ${WRKSRC}/language.dat ${PREFIX}/share/hpack/
	${INSTALL_DATA} ${WRKSRC}/docs/hpack.cfg ${PREFIX}/share/hpack/hpack.cfg.example
	${INSTALL_DATA} ${WRKSRC}/docs/hpackext.doc ${PREFIX}/share/doc/hpack/
	@if [ ! -f ${PREFIX}/etc/hpack.cfg ]; then \
		${CP} -p ${PREFIX}/share/hpack/hpack.cfg.example ${PREFIX}/etc/hpack.cfg; \
	fi

.include "../../mk/bsd.pkg.mk"
