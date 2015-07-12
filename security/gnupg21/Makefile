# $NetBSD: Makefile,v 1.4 2015/07/12 21:12:24 szptvlfn Exp $

DISTNAME=	gnupg-2.1.6
PKGNAME=	${DISTNAME:S/gnupg-/gnupg2-/}
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/gnupg/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ada@netbsdfr.org
HOMEPAGE=	https://www.gnupg.org/
COMMENT=	GNUpg with OpenPGP and S/MIME capabilities
LICENSE=	gnu-gpl-v3

CONFLICTS=	dirmngr-[0-9]*

BUILD_DEFS+=		VARBASE
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config makeinfo
USE_LIBTOOL=		yes
INFO_FILES=		yes
GNU_CONFIGURE=		yes

DEPENDS+=	pinentry-[0-9]*:../../security/pinentry

BUILDLINK_API_DEPENDS.libgpg-error+=	libgpg-error>=1.16
.include "../../security/libgpg-error/buildlink3.mk"
BUILDLINK_API_DEPENDS.libassuan+=	libassuan>=2.1.0
.include "../../security/libassuan2/buildlink3.mk"
.include "../../security/libksba/buildlink3.mk"
BUILDLINK_API_DEPENDS.npth+=		npth>=0.91
.include "../../devel/npth/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
