# $NetBSD: Makefile,v 1.19 2026/01/25 00:59:16 gutteridge Exp $

DISTNAME=	sleuthkit-4.1.3
PKGREVISION=	11
CATEGORIES=	security sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sleuthkit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.sleuthkit.org/
COMMENT=	The Sleuth Kit (TSK) opensource forensic toolkit
LICENSE=	cpl-1.0 AND gnu-gpl-v2

DEPENDS+=	p5-DateTime-TimeZone>=0:../../time/p5-DateTime-TimeZone

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake file perl:run

# Fails with C++14 default language.
FORCE_CXX_STD=	c++03

.include "../../sysutils/file/buildlink3.mk"
.include "../../devel/libewf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
