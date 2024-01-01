# $NetBSD: Makefile,v 1.26 2024/01/01 11:41:38 adam Exp $

DISTNAME=	pcsc-tools-1.7.1
CATEGORIES=	security
MASTER_SITES=	https://pcsc-tools.apdu.fr/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pcsc-tools.apdu.fr/
COMMENT=	Tools useful for a PC/SC user
LICENSE=	gnu-gpl-v2 # or later

DEPENDS+=	p5-pcsc>=1.4.6:../../security/p5-pcsc

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake perl:run pkg-config
GNU_CONFIGURE=	yes

LDFLAGS.NetBSD+=	-lpthread
REPLACE_PERL+=		scriptor gscriptor gscriptor.gtk1.2 ATR_analysis.in

.include "../../security/ccid/buildlink3.mk"
.include "../../security/pcsc-lite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
