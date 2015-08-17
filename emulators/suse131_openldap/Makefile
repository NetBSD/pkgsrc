# $NetBSD: Makefile,v 1.5 2015/08/17 16:13:51 wiz Exp $

PKGNAME=	suse_openldap-${SUSE_VERSION}
PKGREVISION=	1
CATEGORIES=	emulators
RPMUPDPKGS+=	libldap-2_4-2-2.4.33-8.3.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for OpenLDAP

EMUL_MODULES.linux=	base openssl cyrus-sasl

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
