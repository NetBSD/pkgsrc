# $NetBSD: Makefile,v 1.5 2018/08/29 11:12:36 tnn Exp $

DISTNAME=	google-authenticator-libpam-1.05
PKGNAME=	${DISTNAME:S/libpam-//}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_PROJECT=	google-authenticator-libpam
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	https://github.com/google/google-authenticator-libpam
COMMENT=	One-time password generator and PAM module from Google
LICENSE=	apache-2.0

USE_TOOLS=	gmake autoconf automake autoreconf
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

pre-configure:
	cd ${WRKSRC} && autoreconf -vif

.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
