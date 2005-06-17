# $NetBSD: Makefile,v 1.11 2005/06/17 03:50:22 jlam Exp $
#

DISTNAME=       mmv_1.01b.orig
PKGNAME=	mmv-1.0b
CATEGORIES=     misc
MASTER_SITES=   ${MASTER_SITE_DEBIAN:=pool/main/m/mmv/}

MAINTAINER=     tech-pkg@NetBSD.org
HOMEPAGE=       # none
COMMENT=	Move, copy, append or link multiple files using wildcard patterns

WRKSRC=		${WRKDIR}/mmv-1.01b.orig
BUILD_TARGET=	mmv

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CFLAGS+=	-DIS_SYSV
.endif

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mmv ${PREFIX}/bin/mmv
	${INSTALL_MAN} ${WRKSRC}/mmv.1 ${PREFIX}/man/man1/mmv.1

.include "../../mk/bsd.pkg.mk"
