# $NetBSD: Makefile,v 1.1.1.1 2005/12/28 02:08:19 schmonz Exp $
#

DISTNAME=		solfege-3.0.5
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

.include "../../lang/python/application.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
