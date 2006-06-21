# $NetBSD: Makefile,v 1.11 2006/06/21 13:22:27 joerg Exp $
#

DISTNAME=		solfege-3.0.7
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=solfege/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://www.solfege.org/
COMMENT=		Practice several musical ear training exercises

USE_DIRS+=		xdg-1.2
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--disable-oss-sound

USE_TOOLS+=		gmake gm4 makeinfo pkg-config msgfmt

PYTHON_VERSIONS_ACCEPTED=	24 23
PYTHON_PATCH_SCRIPTS=	*.py *.py.in */*.py */*.py.in

EGDIR=			${PREFIX}/share/examples/solfege
CONF_FILES+=		${EGDIR}/${PKGBASE}/solfege ${PKG_SYSCONFDIR}/solfege
INSTALL_MAKE_FLAGS+=	${MAKE_FLAGS} sysconfdir=${EGDIR:Q}

INSTALLATION_DIRS=	${EGDIR}

.include "../../lang/python/application.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
