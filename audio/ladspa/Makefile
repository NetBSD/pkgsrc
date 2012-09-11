# $NetBSD: Makefile,v 1.12 2012/09/12 00:24:40 asau Exp $
#

DISTNAME=	ladspa_sdk_1.13
PKGNAME=	${DISTNAME:S/_sdk_/-/}
CATEGORIES=	audio
MASTER_SITES=	http://www.ladspa.org/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ladspa.org/
COMMENT=	Linux Audio Developers Simple Plugin API
LICENSE=	gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}/ladspa_sdk/src
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

MAKE_FILE=	makefile

BUILDLINK_LIBS.dl+=	${BUILDLINK_LDADD.dl}

INSTALLATION_DIRS+=	bin include lib

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
