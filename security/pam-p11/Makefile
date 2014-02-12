# $NetBSD: Makefile,v 1.8 2014/02/12 23:18:35 tron Exp $
#

DISTNAME=	pam_p11-0.1.5
PKGREVISION=	3
CATEGORIES=	security
MASTER_SITES=	http://www.opensc-project.org/files/pam_p11/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.opensc-project.org/files/pam_p11/
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
