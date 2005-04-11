# $NetBSD: Makefile,v 1.3 2005/04/11 21:44:53 tv Exp $
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
USE_GNU_TOOLS+=	make

MAKEFILE=	makefile

BUILDLINK_LIBS.dl+=	${BUILDLINK_LDADD.dl}

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
