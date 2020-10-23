# $NetBSD: Makefile,v 1.7 2020/10/23 09:20:59 tnn Exp $

DISTNAME=	pam_fprint-0.2
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fprint/}
EXTRACT_SUFX=	.tar.bz2

HOMEPAGE=	http://reactivated.net/fprint/wiki/Pam_fprint
COMMENT=	PAM module to provide authentication using fingerprint readers
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config

.include "../../security/libfprint/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
