# $NetBSD: Makefile,v 1.17 2004/04/26 03:51:52 tv Exp $
#

DISTNAME=	joe2.8
PKGNAME=	joe-2.8
PKGREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.std.com/src/editors/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	explorer@NetBSD.org
COMMENT=	Joe's own editor

WRKSRC=		${WRKDIR}/joe
ALL_TARGET=	joe

CFLAGS+=	-DTERMINFO

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Interix"
CPPFLAGS+=	-Dsetpgrp=setpgid
.endif

.include "../../mk/bsd.pkg.mk"
