# $NetBSD: Makefile,v 1.11 2002/03/14 13:02:30 wiz Exp $

DISTNAME=       hpack79src
PKGNAME=        hpack-0.79
CATEGORIES=	archivers
MASTER_SITES=   ftp://src.doc.ic.ac.uk/packages/hpack/

MAINTAINER=     packages@netbsd.org
COMMENT=	Multi-System Archiver with open keys PGP-based security

CRYPTO=		yes
WRKSRC=		${WRKDIR}

MAKEFILE=       makefile
ALL_TARGET=     hpack

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
MAKE_FLAGS=	CFLAGS="-c -DBSD386 -D__UNIX__ -DPREFIX=\\\"${PREFIX}\\\" -I. ${CFLAGS} -Icrypt" \
		CMDL="${LDFLAGS} -lcurses"
.else
MAKE_FLAGS=	CFLAGS="-c -DBSD386 -D__UNIX__ -DPREFIX=\\\"${PREFIX}\\\" -I. ${CFLAGS} -Icrypt" \
		CMDL="${LDFLAGS} -ltermcap"
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
