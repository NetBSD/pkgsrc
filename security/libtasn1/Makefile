# $NetBSD: Makefile,v 1.81 2021/05/20 10:05:11 wiz Exp $

DISTNAME=	libtasn1-4.17.0
CATEGORIES=	security devel
MASTER_SITES=	${MASTER_SITE_GNU:=libtasn1/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/libtasn1/
COMMENT=	ASN.1 structure parser library
LICENSE=	gnu-fdl-v1.3 AND gnu-lgpl-v2.1 AND gnu-gpl-v3

USE_LIBTOOL=		yes
USE_TOOLS+=		bison makeinfo
USE_LANGUAGES=		c99
GNU_CONFIGURE=		yes

TEST_TARGET=		check
INFO_FILES=		yes

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../mk/bsd.pkg.mk"
