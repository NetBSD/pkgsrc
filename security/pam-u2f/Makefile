# $NetBSD: Makefile,v 1.5 2022/04/12 22:30:55 tnn Exp $

DISTNAME=	pam_u2f-1.2.0
PKGNAME=	${DISTNAME:S/pam_/pam-/}
CATEGORIES=	security
MASTER_SITES=	https://developers.yubico.com/pam-u2f/Releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developers.yubico.com/pam-u2f/
COMMENT=	PAM module for U2F over FIDO2 authentication
LICENSE=	2-clause-bsd

BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

CONFIGURE_ARGS+=	--with-pam-dir=${PREFIX:Q}/lib/security

.include "../../mk/pam.buildlink3.mk"
.include "../../security/libfido2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
