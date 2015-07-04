# $NetBSD: Makefile,v 1.1 2015/07/04 05:26:21 ryoon Exp $

DISTNAME=	gnupg-2.1.6
PKGNAME=	${DISTNAME:S/gnupg-/gnupg2-/}
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/gnupg/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ada@netbsdfr.org
HOMEPAGE=	https://www.gnupg.org/
COMMENT=	GNUpg with OpenPGP and S/MIME capabilities
LICENSE=	gnu-gpl-v3

BUILD_DEFS+=            VARBASE
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config makeinfo
USE_LIBTOOL=		yes
INFO_FILES=		yes
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

BUILDLINK_API_DEPENDS.libgpg-error+=	libgpg-error>=1.4
BUILDLINK_API_DEPENDS.npth+=		npth>=0.91

.include "../../security/libgpg-error/buildlink3.mk"
.include "../../security/libassuan22/buildlink3.mk"
.include "../../security/libksba/buildlink3.mk"
.include "../../devel/npth/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
