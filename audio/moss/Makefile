# $NetBSD: Makefile,v 1.5 2004/10/10 09:48:35 minskim Exp $

DISTNAME=	moss-0.1.11
CATEGORIES=	audio
MASTER_SITES=	http://kldp.net/download.php/1534/

MAINTAINER=	myunggoni@users.kldp.net
HOMEPAGE=	http://moss.kldp.net/
COMMENT=	MP3/OGG Streaming Server

DEPENDS+=	${PYPKGPREFIX}-ogg>=1.3:../../audio/py-ogg
DEPENDS+=	${PYPKGPREFIX}-vorbis>=1.3:../../audio/py-vorbis

USE_BUILDLINK3=	yes
USE_PKGINSTALL= yes

PYTHON_VERSIONS_ACCEPTED=	23pth 22pth 21pth
PYTHON_PATCH_SCRIPTS=	${WRKSRC}/*.py

RCD_SCRIPTS=	moss
CONF_FILES=	${PREFIX}/share/moss/moss.conf.sample	\
		${PKG_SYSCONFDIR}/moss.conf

SUBST_CLASSES+=		path
SUBST_MESSAGE.path=	"Fixing hardcoded paths."
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	moss.conf.sample
SUBST_SED.path=		-e 's,$${PREFIX}/var,${VARBASE},g'	\
			-e 's,$${PREFIX}/share,${PREFIX}/share,g'

FILES_SUBST+=	INTERPRETER=${PYTHONBIN}

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
