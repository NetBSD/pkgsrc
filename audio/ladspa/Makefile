# $NetBSD: Makefile,v 1.9 2006/09/09 02:41:55 obache Exp $
#

DISTNAME=	ladspa_sdk_1.12
PKGNAME=	${DISTNAME:S/_sdk_/-/}
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.ladspa.org/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ladspa.org/
COMMENT=	Linux Audio Developers Simple Plugin API

WRKSRC=		${WRKDIR}/ladspa_sdk/src
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

MAKE_FILE=	makefile

BUILDLINK_LIBS.dl+=	${BUILDLINK_LDADD.dl}

INSTALLATION_DIRS+=	bin include lib

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
