# $NetBSD: Makefile,v 1.6 2012/10/03 21:57:33 wiz Exp $
#

DISTNAME=	pcsc-tools-1.4.15
PKGREVISION=	3
CATEGORIES=	security
MASTER_SITES=	http://ludovic.rousseau.free.fr/softwares/pcsc-tools/

MAINTAINER=	shannonjr@NetBSD.org
HOMEPAGE=	http://ludovic.rousseau.free.fr/softwares/pcsc-tools/
COMMENT=	Tools useful for a PC/SC user
LICENSE=	gnu-gpl-v2 # or later

DEPENDS+=	p5-pcsc-perl>=1.4.6:../../security/p5-pcsc

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config
USE_TOOLS+=	gmake
USE_TOOLS+=	perl:run

DESTDIR_VARNAME=	# empty
INSTALL_ENV+=		DESTDIR=${DESTDIR}${PREFIX:Q}

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix=	ATR_analysis ./ATR_analysis.1p
SUBST_SED.prefix=	-e 's,/usr/local/pcsc,${PREFIX}/share/pcsc,'

REPLACE_PERL+=		scriptor gscriptor gscriptor.gtk1.2 ATR_analysis

.include "../../security/pcsc-lite/buildlink3.mk"
.include "../../security/ccid/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
