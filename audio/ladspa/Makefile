# $NetBSD: Makefile,v 1.5 2006/02/05 23:08:10 joerg Exp $
#

DISTNAME=	ladspa_sdk_1.12
PKGNAME=	${DISTNAME:S/_sdk_/-/}
PKGREVISION=	1
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
