# $NetBSD: Makefile,v 1.15 2020/05/14 18:55:55 joerg Exp $
#

DISTNAME=	pam_p11-0.3.1
#PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=   ${MASTER_SITE_GITHUB:=OpenSC/}
GITHUB_TAG=	pam_p11
GITHUB_RELEASE= pam_p11-0.3.1

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://opensc-project.org/opensc/wiki/pam_p11
COMMENT=	Smart card PAM module
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config autoconf automake autopoint

WRKSRC=	${WRKDIR}/${DISTNAME}
pre-configure:
	cd ${WRKSRC} && autoreconf -f -i

.include "../../security/openssl/buildlink3.mk"
.include "../../security/libp11/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
