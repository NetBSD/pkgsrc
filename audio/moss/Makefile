# $NetBSD: Makefile,v 1.1.1.1 2004/08/10 06:48:21 minskim Exp $

DISTNAME=	moss-0.1.2
CATEGORIES=	audio
MASTER_SITES=	http://kldp.net/download.php/1377/

MAINTAINER=	yongbin@yongbin.com
HOMEPAGE=	http://moss.kldp.net/
COMMENT=	MP3/OGG Streaming Server

DEPENDS+=	${PYPKGPREFIX}-ogg>=1.3:../../audio/py-ogg
DEPENDS+=	${PYPKGPREFIX}-vorbis>=1.3:../../audio/py-vorbis

USE_BUILDLINK3=	yes
USE_PKGINSTALL= yes

PYTHON_PATCH_SCRIPTS=	${WRKSRC}/*.py

RCD_SCRIPTS=	moss
CONF_FILES=	${PREFIX}/share/moss/moss.conf.sample	\
		${PKG_SYSCONFDIR}/moss.conf

SUBST_CLASSES+=		path
SUBST_MESSAGE.path=	"Fixing hardcoded paths."
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	moss.conf.sample
SUBST_SED.path=		-e 's,/usr/local,${PREFIX},g' -e 's,/var,${VARBASE},g'

FILES_SUBST+=	INTERPRETER=${PYTHONBIN}

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
