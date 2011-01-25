# $NetBSD: Makefile,v 1.4 2011/01/25 09:07:58 obache Exp $

DISTNAME=	pam_af-1.0.1
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://mbsd.msk.ru/dist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://mbsd.msk.ru/stas/pam_af.html
COMMENT=	Anti-bruteforce PAM module
LICENSE=	2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "Linux"
.include "../../databases/gdbm/buildlink3.mk"
.endif
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
