# $NetBSD: Makefile,v 1.10 2009/07/07 15:23:05 joerg Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/ladspa_sdk/src
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

MAKE_FILE=	makefile

BUILDLINK_LIBS.dl+=	${BUILDLINK_LDADD.dl}

INSTALLATION_DIRS+=	bin include lib

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
