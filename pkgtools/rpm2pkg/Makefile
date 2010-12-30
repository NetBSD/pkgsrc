# $NetBSD: Makefile,v 1.55 2010/12/30 00:39:15 tron Exp $

DISTNAME=	rpm2pkg-3.1.8
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty
NO_CHECKSUM=	yes

OWNER=		tron@NetBSD.org
HOMEPAGE=	http://www.NetBSD.org/docs/pkgsrc/
COMMENT=	Convert RPM archives to NetBSD packages
LICENSE=	modified-bsd

CONFLICTS+=	suse-base<=6.4

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c99
USE_TOOLS+=	xzcat:run
WRKSRC=		${WRKDIR}

CPPFLAGS+=	${BUILDLINK_CPPFLAGS.bzip2} \
		${BUILDLINK_CPPFLAGS.zlib} -DXZCAT=\"${TOOLS_PATH.xzcat:Q}\"
LIBS+=		-lz -lbz2

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-*)
CFLAGS+=	-Wall -Wshadow -Wsign-compare -Wunused-value
.endif

CFLAGS+=	-g

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin

do-build:
	cd ${WRKSRC}; ${CC} ${CFLAGS} ${CPPFLAGS} ${LDFLAGS} -o rpm2pkg \
		${FILESDIR}/rpm2pkg.c ${LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rpm2pkg ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${FILESDIR}/rpm2pkg.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
