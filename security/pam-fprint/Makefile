# $NetBSD: Makefile,v 1.6 2016/02/26 09:41:06 jperkin Exp $

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

# Fix (workaround?) a bug with openpam/NetBSD
# The bug is described in PR security/39313.
CFLAGS.NetBSD+=	-DNO_STATIC_MODULES

.include "../../security/libfprint/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
