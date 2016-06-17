# $NetBSD: Makefile,v 1.6 2016/06/17 17:21:39 tsutsui Exp $

PKGNAME=	suse_openldap-${SUSE_VERSION}
PKGREVISION=	2
CATEGORIES=	emulators
RPMUPDPKGS+=	libldap-2_4-2-2.4.33-8.9.2.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for OpenLDAP

EMUL_MODULES.linux=	base openssl cyrus-sasl

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
