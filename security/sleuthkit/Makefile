# $NetBSD: Makefile,v 1.11 2018/08/23 07:47:34 he Exp $

DISTNAME=	sleuthkit-4.1.3
PKGREVISION=	6
CATEGORIES=	security sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sleuthkit/}

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://www.sleuthkit.org/
COMMENT=	The Sleuth Kit (TSK) opensource forensic toolkit
LICENSE=	cpl-1.0 AND gnu-gpl-v2

DEPENDS+=	p5-DateTime-TimeZone>=0:../../time/p5-DateTime-TimeZone

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++03
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake file perl:run

.include "../../sysutils/file/buildlink3.mk"
.include "../../devel/libewf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
