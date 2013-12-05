# $NetBSD: Makefile,v 1.1 2013/12/05 11:42:16 obache Exp $

DISTNAME=	suse_openldap-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libldap-2_4-2-2.4.33-8.1.2.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for OpenLDAP

EMUL_MODULES.linux=	base openssl cyrus-sasl

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
