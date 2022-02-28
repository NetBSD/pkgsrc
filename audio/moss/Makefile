# $NetBSD: Makefile,v 1.37 2022/02/28 10:06:34 wiz Exp $

DISTNAME=	moss-0.1.13
PKGREVISION=	9
CATEGORIES=	audio
MASTER_SITES=	http://kldp.net/frs/download.php/1580/

MAINTAINER=	myunggoni@users.kldp.net
HOMEPAGE=	https://moss.kldp.net/
COMMENT=	MP3/OGG Streaming Server
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-ogg>=1.3:../../audio/py-ogg
DEPENDS+=	${PYPKGPREFIX}-vorbis>=1.3:../../audio/py-vorbis

PYTHON_VERSIONS_ACCEPTED=	27 # py-ogg, py-vorbis

REPLACE_PYTHON=	*.py

RCD_SCRIPTS=	moss
CONF_FILES=	${PREFIX}/share/moss/moss.conf.sample	\
		${PKG_SYSCONFDIR}/moss.conf

BUILD_DEFS+=	VARBASE

SUBST_CLASSES+=		path
SUBST_MESSAGE.path=	Fixing hardcoded paths.
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	moss.conf.sample
SUBST_SED.path=		-e 's,$${PREFIX}/var,${VARBASE},g'
SUBST_SED.path+=	-e 's,$${PREFIX}/share,${PREFIX}/share,g'

FILES_SUBST+=	INTERPRETER=${PYTHONBIN:Q}

.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
