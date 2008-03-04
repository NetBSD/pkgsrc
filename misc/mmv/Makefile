# $NetBSD: Makefile,v 1.15 2008/03/04 19:21:11 jlam Exp $
#

DISTNAME=	mmv_1.01b.orig
PKGNAME=	mmv-1.0b
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/m/mmv/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	# none
COMMENT=	Move, copy, append or link multiple files using wildcard patterns

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/mmv-1.01b.orig
BUILD_TARGET=	mmv

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CFLAGS+=	-DIS_SYSV
.endif

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mmv ${DESTDIR}${PREFIX}/bin/mmv
	${INSTALL_MAN} ${WRKSRC}/mmv.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/mmv.1

.include "../../mk/bsd.pkg.mk"
