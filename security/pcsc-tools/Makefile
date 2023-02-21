# $NetBSD: Makefile,v 1.24 2023/02/21 16:34:14 adam Exp $

DISTNAME=	pcsc-tools-1.6.2
CATEGORIES=	security
MASTER_SITES=	https://pcsc-tools.apdu.fr/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pcsc-tools.apdu.fr/
COMMENT=	Tools useful for a PC/SC user
LICENSE=	gnu-gpl-v2 # or later

DEPENDS+=	p5-pcsc>=1.4.6:../../security/p5-pcsc

USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake autoreconf gmake perl:run pkg-config
GNU_CONFIGURE=	yes

LDFLAGS.NetBSD+=	-lpthread

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	ATR_analysis ./ATR_analysis.1p
SUBST_SED.prefix=	-e 's,/usr/local/pcsc,${PREFIX}/share/pcsc,'

REPLACE_PERL+=		scriptor gscriptor gscriptor.gtk1.2 ATR_analysis

pre-configure:
	cd ${WRKSRC} && autoreconf -fi

.include "../../security/pcsc-lite/buildlink3.mk"
.include "../../security/ccid/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
