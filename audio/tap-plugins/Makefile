# $NetBSD: Makefile,v 1.3 2015/03/17 13:41:09 jperkin Exp $
#

DISTNAME=	tap-plugins-0.7.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tap-plugins/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://tap-plugins.sourceforge.net/ladspa.html
COMMENT=	Tom's Audio Processing plugins
LICENSE=	gnu-gpl-v2

USE_GCC_RUNTIME=	yes

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_MESSAGE.prefix=	Fixing PREFIX.
SUBST_FILES.prefix=	Makefile
SUBST_SED.prefix=	-e 's|/usr/local|${DESTDIR}${PREFIX}|'

INSTALLATION_DIRS+=	lib/ladspa share/ladspa/rdf

.include "../../mk/bsd.pkg.mk"
