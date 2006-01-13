# $NetBSD: Makefile,v 1.2 2006/01/13 21:23:42 schmonz Exp $
#

DISTNAME=		solfege-3.0.5
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=solfege/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://www.solfege.org/
COMMENT=		Practice several musical ear training exercises

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--disable-oss-sound

USE_TOOLS+=		gmake gm4 pkg-config
USE_MAKEINFO=		yes

PYTHON_VERSIONS_ACCEPTED=	24 23
PYTHON_PATCH_SCRIPTS=	*.py *.py.in */*.py */*.py.in

CONF_FILES=		${PREFIX}/share/examples/solfege/system.rc
CONF_FILES+=		${PKG_SYSCONFDIR}/solfege

INSTALLATION_DIRS=	share/examples/solfege

.include "../../lang/python/application.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
