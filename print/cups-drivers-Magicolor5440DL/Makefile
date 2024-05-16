# $NetBSD: Makefile,v 1.49 2024/05/16 06:15:27 wiz Exp $
#

DISTNAME=	5440DL_lin64bit_1_2_1
PKGNAME=	cups-drivers-Magicolor5440DL-1.2.1
PKGREVISION=	39
CATEGORIES=	print
MASTER_SITES=	#
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://printer.konicaminolta.com/support/current_printers/mc5440dl_sup.htm
COMMENT=	CUPS drivers for printer Konica Minolta Magicolor 5440DL
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	jbigkit>=1.6:../../graphics/jbigkit

GHOSTSCRIPT_REQD=	8.0
USE_TOOLS+=		gs:run

WRKSRC=		${WRKDIR}/5440DL_64_v1.2.1/magicolor5440DL-1.2.1/

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

LDFLAGS.DragonFly=	-lm
LDFLAGS.SunOS+=		-lm

post-extract:
	cd ${WRKDIR}/5440DL_64_v1.2.1/; \
		extract_file=src/magicolor5440DL-1.2.1.tar.gz; ${EXTRACT_CMD}

.include "../../graphics/lcms/buildlink3.mk"
.include "../../graphics/jbigkit/buildlink3.mk"
.include "../../print/cups-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
