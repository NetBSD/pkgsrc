# $NetBSD: Makefile,v 1.11 2016/03/05 11:29:24 jperkin Exp $
#

DISTNAME=	pam_p11-0.1.5
PKGREVISION=	4
CATEGORIES=	security
# This has a bad name and doesn't have generated auto* files.
#MASTER_SITES=	https://github.com/OpenSC/pam_p11/archive/
MASTER_SITES=	${MASTER_SITE_BACKUP}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://opensc-project.org/opensc/wiki/pam_p11
COMMENT=	Smart card PAM module
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config autoconf automake

pre-configure:
	cd ${WRKSRC} && autoreconf -f -i

.include "../../security/openssl/buildlink3.mk"
.include "../../security/libp11/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
