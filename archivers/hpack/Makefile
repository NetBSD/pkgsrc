# $NetBSD: Makefile,v 1.41 2019/08/05 19:21:12 maya Exp $

DISTNAME=	hpack79src
PKGNAME=	hpack-0.79
PKGREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.csc.fi/index/crypt/archive/idea.sec.dsi.unimi.it/code/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Multi-System Archiver with open keys PGP-based security

DIST_SUBDIR=	${PKGNAME_NOREV}
WRKSRC=		${WRKDIR}
MAKE_FILE=	makefile
MAKE_FLAGS+=	CFLAGS=${HPACK_CFLAGS:Q} CMDL=${HPACK_LDFLAGS:Q}
BUILD_TARGET=	hpack
USE_LANGUAGES=	c

.include "../../mk/bsd.prefs.mk"

CFLAGS+=	-std=gnu89

.if ${OPSYS} == "Linux"
HPACK_CFLAGS=	-DLINUX
.else
HPACK_CFLAGS=	-DBSD386
.endif
HPACK_CFLAGS+=	-c -D__UNIX__ -DPREFIX="\"${PREFIX}\"" -I. -Icrypt
HPACK_CFLAGS+=	${CPPFLAGS} ${CFLAGS}
HPACK_LDFLAGS=	${LDFLAGS} ${BUILDLINK_LDADD.termcap}

CONF_FILES=	${PREFIX}/share/hpack/hpack.cfg.example		\
		${PKG_SYSCONFDIR}/hpack.cfg

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/hpack share/doc/hpack

post-build:
	cd ${WRKSRC}/keycvt && ${BUILD_MAKE_CMD} keycvt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hpack \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/keycvt/keycvt \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/hpack.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/language.dat \
		${DESTDIR}${PREFIX}/share/hpack
	${INSTALL_DATA} ${WRKSRC}/docs/hpack.cfg \
		${DESTDIR}${PREFIX}/share/hpack/hpack.cfg.example
	${INSTALL_DATA} ${WRKSRC}/docs/hpackext.doc \
		${DESTDIR}${PREFIX}/share/doc/hpack

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
