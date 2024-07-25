# $NetBSD: Makefile,v 1.7 2024/07/25 05:41:52 wiz Exp $

DISTNAME=	google-authenticator-libpam-1.09
PKGNAME=	${DISTNAME:S/libpam-//}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_PROJECT=	google-authenticator-libpam
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/google-authenticator-libpam
COMMENT=	One-time password generator and PAM module from Google
LICENSE=	apache-2.0

USE_TOOLS=	gmake autoconf automake autoreconf
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

pre-configure:
	cd ${WRKSRC} && autoreconf -vif

.include "../../converters/qrencode/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
