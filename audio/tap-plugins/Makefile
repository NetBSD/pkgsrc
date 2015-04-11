# $NetBSD: Makefile,v 1.4 2015/04/11 01:26:56 rodent Exp $
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

.if ${OPSYS} == "OpenBSD"
BUILDLINK_TRANSFORM+=	rm:-lrt
.elif ${OPSYS} == "Darwin"
BUILDLINK_TRANSFORM+=	rm:-Bsymbolic
.endif

.include "../../mk/bsd.pkg.mk"
