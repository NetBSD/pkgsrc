# $NetBSD: Makefile,v 1.95 2024/03/09 00:08:04 js Exp $

DISTNAME=	matrix-synapse-1.102.0
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=element-hq/}
GITHUB_PROJECT=	synapse
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	js@NetBSD.org
#MAINTAINER+=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/element-hq/synapse/
COMMENT=	Reference homeserver for the Matrix decentralised comms protocol
LICENSE=	gnu-agpl-v3

# Build tools:
TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-[0-9]*:../../devel/py-poetry
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-rust>=1.3:../../devel/py-setuptools-rust

# Dependencies as defined by synapse's build system (in theory):
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=16.0.0:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-Pillow>=10.0.1:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-asn1>=0.1.9:../../security/py-asn1
DEPENDS+=	${PYPKGPREFIX}-asn1-modules>=0.0.7:../../security/py-asn1-modules
DEPENDS+=	${PYPKGPREFIX}-attrs>=21.1.1:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-bcrypt>=3.1.7:../../security/py-bcrypt
DEPENDS+=	${PYPKGPREFIX}-bleach>=1.4.3:../../www/py-bleach
DEPENDS+=	${PYPKGPREFIX}-canonicaljson>=2.0.0:../../devel/py-canonicaljson
DEPENDS+=	${PYPKGPREFIX}-cryptography>=3.4.7:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-ijson>=3.1.4:../../devel/py-ijson
DEPENDS+=	${PYPKGPREFIX}-immutabledict>=2.0:../../devel/py-immutabledict
DEPENDS+=	${PYPKGPREFIX}-jinja2>=3.0:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=3.0.0:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-macaroons>=0.13.0:../../devel/py-macaroons
DEPENDS+=	${PYPKGPREFIX}-matrix-common>=1.3.0:../../chat/py-matrix-common
DEPENDS+=	${PYPKGPREFIX}-msgpack>=0.5.2:../../devel/py-msgpack
DEPENDS+=	${PYPKGPREFIX}-netaddr>=0.7.18:../../net/py-netaddr
DEPENDS+=	${PYPKGPREFIX}-packaging>=20.0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-phonenumbers>=8.2.0:../../textproc/py-phonenumbers
DEPENDS+=	${PYPKGPREFIX}-prometheus_client>=0.4.0:../../net/py-prometheus_client
DEPENDS+=	${PYPKGPREFIX}-pydantic>=1.7.4<3:../../devel/py-pydantic
DEPENDS+=	${PYPKGPREFIX}-service_identity>=18.1.0:../../security/py-service_identity
DEPENDS+=	${PYPKGPREFIX}-signedjson>=1.1.0:../../security/py-signedjson
DEPENDS+=	${PYPKGPREFIX}-sortedcontainers>=1.5.2:../../devel/py-sortedcontainers
DEPENDS+=	${PYPKGPREFIX}-treq>=15.1:../../devel/py-treq
DEPENDS+=	${PYPKGPREFIX}-twisted>=18.9.0:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.10.0.1:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-unpaddedbase64>=1.1.0:../../devel/py-unpaddedbase64
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.13:../../textproc/py-yaml
# jwt/oidc
DEPENDS+=	${PYPKGPREFIX}-authlib>=0.15.1:../../security/py-authlib
# postgres
DEPENDS+=	${PYPKGPREFIX}-psycopg2>=2.8:../../databases/py-psycopg2
# url-preview
DEPENDS+=	${PYPKGPREFIX}-lxml>=4.2.0:../../textproc/py-lxml
# NB: synapse needs features missing in NetBSD base system sqlite, and probably
# missing in other builds.
TEST_DEPENDS+=	${PYPKGPREFIX}-idna-[0-9]*:../../www/py-idna
TEST_DEPENDS+=	${PYPKGPREFIX}-parameterized-[0-9]*:../../devel/py-parameterized

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_CC_FEATURES=	c99

REPLACE_PYTHON+=	synapse/_scripts/*.py

USE_TOOLS+=	perl:run

# Avoid the pyNN- prefix in config, doc, and so on.
HUMAN_PKGNAME=		matrix-synapse
PKG_SYSCONFSUBDIR=	${HUMAN_PKGNAME}
DOCDIR=			${PREFIX}/share/doc/${HUMAN_PKGNAME}

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

SYNAPSE_USER?=	synapse
SYNAPSE_GROUP?=	${SYNAPSE_USER}
SYNAPSE_DATA?=	${VARBASE}/db/${HUMAN_PKGNAME}
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
SUBST_STAGE.pl=			post-configure
SUBST_FILES.pl=			synapse/handlers/room.py
SUBST_VARS.pl=			SYNAPSE_DEFAULT_CREATOR_PL

BUILD_DEFS+=			SYNAPSE_DEFAULT_CREATOR_PL

post-patch:
	# Otherwise, this file is installed and pollutes PLIST.
	rm ${WRKSRC}/synapse/handlers/room.py.orig

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} files/README.pkgsrc.txt ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} files/README.pkgsrc.NetBSD.txt ${DESTDIR}${DOCDIR}

# \todo Grok upstream's new test scheme and port to it.
# As of 1.98.0 all tests fail, most of them failing to import
# synapse.synapse_rust.
# Quick fix before running tests: rm -r ${WRKSRC}/synapse

# New upstream releases typically add/change cargo depends.
.PHONY: update-cargo
update-cargo:
	make extract && make print-cargo-depends > cargo-depends.mk && make distinfo

# guide says "Prepend .include "cargo-depends.mk" to any other .includes."
# To start:
#   make CARGO_ARGS="build --release" build && make print-cargo-depends > cargo-depends.mk
.include "cargo-depends.mk"

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
RUST_REQ=	1.51.0
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
