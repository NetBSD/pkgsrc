# $NetBSD: Makefile,v 1.11 2009/08/16 14:17:44 wiz Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/ladspa_sdk/src
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

MAKE_FILE=	makefile

BUILDLINK_LIBS.dl+=	${BUILDLINK_LDADD.dl}

INSTALLATION_DIRS+=	bin include lib

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
