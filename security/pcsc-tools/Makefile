# $NetBSD: Makefile,v 1.3 2009/03/16 19:14:08 hasso Exp $
#

DISTNAME=	pcsc-tools-1.4.15
CATEGORIES=	security
MASTER_SITES=	http://ludovic.rousseau.free.fr/softwares/pcsc-tools/

MAINTAINER=	shannonjr@NetBSD.org
HOMEPAGE=	http://ludovic.rousseau.free.fr/softwares/pcsc-tools/
COMMENT=	Some tools usefull for a PC/SC user.

DEPENDS+=	p5-pcsc-perl>=1.4.6:../../security/p5-pcsc

USE_TOOLS+=	pkg-config
USE_TOOLS+=	gmake
USE_TOOLS+=	perl:run

INSTALL_ENV+=	DESTDIR=${PREFIX:Q}

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix=	ATR_analysis ./ATR_analysis.1p
SUBST_SED.prefix=	-e 's,/usr/local/pcsc,${PREFIX}/share/pcsc,'

SUBST_CLASSES+=		perl
SUBST_STAGE.perl=	post-patch
SUBST_FILES.perl=	scriptor gscriptor gscriptor.gtk1.2 ATR_analysis
SUBST_SED.perl=		-e 's,perl,${PERL5},'

.include "../../security/pcsc-lite/buildlink3.mk"
.include "../../security/ccid/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
