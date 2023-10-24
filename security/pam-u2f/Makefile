# $NetBSD: Makefile,v 1.7 2023/10/24 22:10:55 wiz Exp $

DISTNAME=	pam_u2f-1.2.0
PKGNAME=	${DISTNAME:S/pam_/pam-/}
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://developers.yubico.com/pam-u2f/Releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developers.yubico.com/pam-u2f/
COMMENT=	PAM module for U2F over FIDO2 authentication
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

CONFIGURE_ARGS+=	--with-pam-dir=${PREFIX:Q}/lib/security

.include "../../mk/pam.buildlink3.mk"
.include "../../security/libfido2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
