# $NetBSD: Makefile,v 1.53 2022/06/28 11:31:04 wiz Exp $

DISTNAME=	matrix-synapse-1.61.0
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=matrix-org/}
GITHUB_PROJECT=	synapse
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	js@pkgsrc.org
HOMEPAGE=	https://github.com/matrix-org/synapse/
COMMENT=	Reference homeserver for the Matrix decentralised comms protocol
LICENSE=	apache-2.0

# Build tools:
TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-[0-9]*:../../devel/py-poetry

# Dependencies as defined by synapse's build system (in theory):
DEPENDS+=	${PYPKGPREFIX}-asn1-modules>=0.0.7:../../security/py-asn1-modules
DEPENDS+=	${PYPKGPREFIX}-asn1>=0.1.9:../../security/py-asn1
DEPENDS+=	${PYPKGPREFIX}-attrs>=19.2.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-bcrypt>=3.1.0:../../security/py-bcrypt
DEPENDS+=	${PYPKGPREFIX}-bleach>=1.4.3:../../www/py-bleach
DEPENDS+=	${PYPKGPREFIX}-canonicaljson>=1.4.0:../../devel/py-canonicaljson
DEPENDS+=	${PYPKGPREFIX}-curses-[0-9]*:../../devel/py-curses
DEPENDS+=	${PYPKGPREFIX}-frozendict>=1:../../devel/py-frozendict
DEPENDS+=	${PYPKGPREFIX}-idna>=2.5:../../www/py-idna
DEPENDS+=	${PYPKGPREFIX}-ijson>=3.0:../../devel/py-ijson
DEPENDS+=	${PYPKGPREFIX}-jinja2>=3.0:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=3.0.0:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-lxml>=3.5.0:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-macaroons>=0.13.0:../../devel/py-macaroons
DEPENDS+=	${PYPKGPREFIX}-matrix-common>=1.1.0:../../chat/py-matrix-common
DEPENDS+=	${PYPKGPREFIX}-msgpack>=0.5.2:../../devel/py-msgpack
DEPENDS+=	${PYPKGPREFIX}-nacl>=1.2.1:../../security/py-nacl
DEPENDS+=	${PYPKGPREFIX}-netaddr>=0.7.18:../../net/py-netaddr
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=16.0.0:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-phonenumbers>=8.2.0:../../textproc/py-phonenumbers
DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-prometheus_client>=0.4.0:../../net/py-prometheus_client
DEPENDS+=	${PYPKGPREFIX}-psycopg2>=2.7:../../databases/py-psycopg2
DEPENDS+=	${PYPKGPREFIX}-service_identity>=18.1.0:../../security/py-service_identity
DEPENDS+=	${PYPKGPREFIX}-signedjson>=1.1.0:../../security/py-signedjson
DEPENDS+=	${PYPKGPREFIX}-sortedcontainers>=1.4.4:../../devel/py-sortedcontainers
DEPENDS+=	${PYPKGPREFIX}-sqlite3>=0:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-treq>=15.1:../../devel/py-treq
DEPENDS+=	${PYPKGPREFIX}-twisted>=18.9.0:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.10.0:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-unpaddedbase64>=1.1.0:../../devel/py-unpaddedbase64
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.11:../../textproc/py-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-parameterized-[0-9]*:../../devel/py-parameterized
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-unpaddedbase64

USE_PKG_RESOURCES=	yes

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	synapse/_scripts/*.py

USE_TOOLS+=	perl:run
REPLACE_PERL+=	scripts/sync_room_to_group.pl

PKG_SYSCONFSUBDIR=	matrix-synapse

SYNAPSE_USER?=	synapse
SYNAPSE_GROUP?=	${SYNAPSE_USER}
SYNAPSE_DATA?=	${VARBASE}/db/matrix-synapse
BUILD_DEFS+=	SYNAPSE_USER SYNAPSE_GROUP SYNAPSE_DATA VARBASE

OWN_DIRS_PERMS+=		${SYNAPSE_DATA} ${SYNAPSE_USER} ${SYNAPSE_GROUP} 0770

PKG_USERS_VARS=			SYNAPSE_USER
PKG_GROUPS_VARS=		SYNAPSE_GROUP
PKG_GROUPS=			${SYNAPSE_GROUP}
PKG_USERS=			${SYNAPSE_USER}:${SYNAPSE_GROUP}
PKG_GECOS.${SYNAPSE_USER}=	Synapse daemon user
PKG_HOME.${SYNAPSE_USER}=	${SYNAPSE_DATA}
PKG_SHELL.${SYNAPSE_USER}=	${NOLOGIN}

RCD_SCRIPTS=	matrix-synapse

FILES_SUBST+=	SYNAPSE_DATA=${SYNAPSE_DATA:Q}
FILES_SUBST+=	SYNAPSE_USER=${SYNAPSE_USER:Q}
FILES_SUBST+=	SYNAPSE_GROUP=${SYNAPSE_GROUP:Q}
MESSAGE_SUBST+=	PYTHONBIN=${PYTHONBIN:Q}
MESSAGE_SUBST+=	SYNAPSE_DATA=${SYNAPSE_DATA:Q}

SYNAPSE_DEFAULT_CREATOR_PL?=	100
SUBST_CLASSES+=			pl
SUBST_STAGE.pl=			post-patch
SUBST_FILES.pl=			synapse/handlers/room.py
SUBST_VARS.pl=			SYNAPSE_DEFAULT_CREATOR_PL

BUILD_DEFS+=			SYNAPSE_DEFAULT_CREATOR_PL

post-patch:
	# Otherwise, this file is installed and pollutes PLIST.
	rm ${WRKSRC}/synapse/handlers/room.py.orig

# \todo Grok upstream's new test scheme and port to it.
# test status as of 1.51.0
# 51 warnings, 1 error
do-test:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
