# $NetBSD: Makefile,v 1.34 2006/10/03 19:48:43 rillig Exp $

DISTNAME=	hpack79src
PKGNAME=	hpack-0.79
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.franken.de/pub/crypt/misc/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Multi-System Archiver with open keys PGP-based security

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}

CRYPTO=		yes

MAKE_FILE=	makefile
BUILD_TARGET=	hpack

DIST_SUBDIR=	${PKGNAME_NOREV}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
MAKE_FLAGS+=	CFLAGS='-c -DLINUX -D__UNIX__ -DPREFIX="\"${PREFIX}\"" -I. '${CFLAGS:Q}' -Icrypt'
.else
MAKE_FLAGS+=	CFLAGS='-c -DBSD386 -D__UNIX__ -DPREFIX="\"${PREFIX}\"" -I. '${CFLAGS:Q}' -Icrypt'
.endif

.if ${OPSYS} == "Darwin"
MAKE_FLAGS+=	CMDL=${LDFLAGS:Q}' -lcurses'
.else
MAKE_FLAGS+=	CMDL=${LDFLAGS:Q}' -ltermcap'
.endif

CONF_FILES=	${PREFIX}/share/hpack/hpack.cfg.example	\
		${PKG_SYSCONFDIR}/hpack.cfg

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/hpack share/doc/hpack

post-build:
	cd ${WRKSRC}/keycvt && ${MAKE} CFLAGS="-c -D__UNIX__ "${CFLAGS:Q} \
		-f ${MAKE_FILE} keycvt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hpack ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/keycvt/keycvt ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/docs/hpack.1 ${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA} ${WRKSRC}/language.dat ${PREFIX}/share/hpack/
	${INSTALL_DATA} ${WRKSRC}/docs/hpack.cfg ${PREFIX}/share/hpack/hpack.cfg.example
	${INSTALL_DATA} ${WRKSRC}/docs/hpackext.doc ${PREFIX}/share/doc/hpack/

.include "../../mk/bsd.pkg.mk"
