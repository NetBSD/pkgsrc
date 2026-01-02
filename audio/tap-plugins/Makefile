# $NetBSD: Makefile,v 1.14 2026/01/02 09:21:48 wiz Exp $

DISTNAME=	tap-plugins-0.7.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tap-plugins/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tomscii.sig7.se/tap-plugins/
COMMENT=	Tom's Audio Processing plugins
LICENSE=	gnu-gpl-v2

USE_GCC_RUNTIME=	yes

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Fixing PREFIX.
SUBST_FILES.prefix=	Makefile
SUBST_SED.prefix=	-e 's|/usr/local|${DESTDIR}${PREFIX}|'

INSTALLATION_DIRS+=	lib/ladspa share/ladspa/rdf

BUILDLINK_TRANSFORM.Darwin+=	rm:-Wl,-Bsymbolic
BUILDLINK_TRANSFORM.OpenBSD+=	rm:-lrt

.include "../../mk/bsd.pkg.mk"
