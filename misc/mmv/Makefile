# $NetBSD: Makefile,v 1.6 2003/09/22 09:56:24 wiz Exp $
#

DISTNAME=       mmv_1.01b.orig
PKGNAME=	mmv-1.0b
WRKSRC=		${WRKDIR}/mmv-1.01b.orig
CATEGORIES=     misc
MASTER_SITES=   ${MASTER_SITE_DEBIAN:=dists/potato/main/source/utils/}

MAINTAINER=     tech-pkg@NetBSD.org
HOMEPAGE=       # none
COMMENT=	mmv is a program to move multiple files using wildcard patterns

ALL_TARGET=	mmv

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CFLAGS+=	-DIS_SYSV
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mmv ${PREFIX}/bin/mmv
	${INSTALL_MAN} ${WRKSRC}/mmv.1 ${PREFIX}/man/man1/mmv.1

.include "../../mk/bsd.pkg.mk"
