# $NetBSD: Makefile,v 1.2 2005/03/31 17:17:06 minskim Exp $
#

DISTNAME=	ladspa_sdk_1.12
PKGNAME=	${DISTNAME:S/_sdk_/-/}
CATEGORIES=	audio
MASTER_SITES=	http://www.ladspa.org/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.ladspa.org/
COMMENT=	Linux Audio Developers Simple Plugin API

WRKSRC=		${WRKDIR}/ladspa_sdk/src
USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make

MAKEFILE=	makefile

BUILDLINK_LIBS.dl+=	${BUILDLINK_LDADD.dl}

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
