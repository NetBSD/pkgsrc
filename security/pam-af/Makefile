# $NetBSD: Makefile,v 1.1.1.1 2007/01/08 05:49:01 obache Exp $

DISTNAME=	pam_af-1.0.1
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	security
MASTER_SITES=	http://mbsd.msk.ru/dist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://mbsd.msk.ru/stas/pam_af.html
COMMENT=	Anti-bruteforce PAM module

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "Linux"
.include "../../databases/gdbm/buildlink3.mk"
.endif
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
