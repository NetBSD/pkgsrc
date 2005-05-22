# $NetBSD: Makefile,v 1.4 2005/05/22 20:07:38 jlam Exp $
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
USE_TOOLS+=	gmake

MAKEFILE=	makefile

BUILDLINK_LIBS.dl+=	${BUILDLINK_LDADD.dl}

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
