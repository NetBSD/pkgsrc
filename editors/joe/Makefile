# $NetBSD: Makefile,v 1.18 2004/06/02 20:22:54 reed Exp $
#

DISTNAME=	joe2.8
PKGNAME=	joe-2.8
PKGREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.std.com/src/editors/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Joe's own editor

WRKSRC=		${WRKDIR}/joe
ALL_TARGET=	joe

CFLAGS+=	-DTERMINFO

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Interix"
CPPFLAGS+=	-Dsetpgrp=setpgid
.endif

.include "../../mk/bsd.pkg.mk"
