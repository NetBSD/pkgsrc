# $NetBSD: Makefile,v 1.83 2023/10/26 22:46:47 gdt Exp $

DISTNAME=	matrix-synapse-1.95.0
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=matrix-org/}
GITHUB_PROJECT=	synapse
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	js@NetBSD.org
#MAINTAINER+=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/matrix-org/synapse/
COMMENT=	Reference homeserver for the Matrix decentralised comms protocol
LICENSE=	apache-2.0

# Build tools:
TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-[0-9]*:../../devel/py-poetry
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-rust-[0-9]*:../../devel/py-setuptools-rust

# Dependencies as defined by synapse's build system (in theory):
# \todo Go over poetry.lock
DEPENDS+=	${PYPKGPREFIX}-asn1-modules>=0.0.7:../../security/py-asn1-modules
DEPENDS+=	${PYPKGPREFIX}-asn1>=0.1.9:../../security/py-asn1
DEPENDS+=	${PYPKGPREFIX}-pydantic>=1.9.1<2:../../devel/py-pydantic
DEPENDS+=	${PYPKGPREFIX}-attrs>=19.2.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-bcrypt>=3.1.0:../../security/py-bcrypt
DEPENDS+=	${PYPKGPREFIX}-bleach>=1.4.3:../../www/py-bleach
DEPENDS+=	${PYPKGPREFIX}-canonicaljson>=2.0.0:../../devel/py-canonicaljson
DEPENDS+=	${PYPKGPREFIX}-immutabledict>=2.0:../../devel/py-immutabledict
DEPENDS+=	${PYPKGPREFIX}-idna>=2.5:../../www/py-idna
DEPENDS+=	${PYPKGPREFIX}-ijson>=3.0:../../devel/py-ijson
DEPENDS+=	${PYPKGPREFIX}-jinja2>=3.0:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=3.0.0:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-lxml>=3.5.0:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-macaroons>=0.13.0:../../devel/py-macaroons
DEPENDS+=	${PYPKGPREFIX}-matrix-common>=1.2.0:../../chat/py-matrix-common
DEPENDS+=	${PYPKGPREFIX}-msgpack>=0.5.2:../../devel/py-msgpack
DEPENDS+=	${PYPKGPREFIX}-nacl>=1.2.1:../../security/py-nacl
DEPENDS+=	${PYPKGPREFIX}-netaddr>=0.7.18:../../net/py-netaddr
DEPENDS+=	${PYPKGPREFIX}-phonenumbers>=8.2.0:../../textproc/py-phonenumbers
DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-prometheus_client>=0.4.0:../../net/py-prometheus_client
DEPENDS+=	${PYPKGPREFIX}-psycopg2>=2.7:../../databases/py-psycopg2
DEPENDS+=	${PYPKGPREFIX}-service_identity>=18.1.0:../../security/py-service_identity
DEPENDS+=	${PYPKGPREFIX}-signedjson>=1.1.0:../../security/py-signedjson
DEPENDS+=	${PYPKGPREFIX}-sortedcontainers>=1.4.4:../../devel/py-sortedcontainers
# NB: synapse needs features missing in NetBSD base system sqlite, and probably
# missing in other builds.
DEPENDS+=	${PYPKGPREFIX}-treq>=15.1:../../devel/py-treq
DEPENDS+=	${PYPKGPREFIX}-twisted>=18.9.0:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.10.0:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-unpaddedbase64>=1.1.0:../../devel/py-unpaddedbase64
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.11:../../textproc/py-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-parameterized-[0-9]*:../../devel/py-parameterized
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-unpaddedbase64

USE_LANGUAGES=	c99

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

.if ${OPSYS} == "Darwin"
post-install: fix-rpath
.PHONY: fix-rpath
fix-rpath:
	install_name_tool -id ${PREFIX}/${PYSITELIB}/synapse/synapse_rust.abi3.so \
	${DESTDIR}${PREFIX}/${PYSITELIB}/synapse/synapse_rust.abi3.so
.endif

# \todo Grok upstream's new test scheme and port to it.
# test status as of 1.51.0
# 51 warnings, 1 error
do-test:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} pytest-${PYVERSSUFFIX}

# guide says "Prepend .include "cargo-depends.mk" to any other .includes."
# To start:
#   make CARGO_ARGS="build --release" build && make print-cargo-depends > cargo-depends.mk
# To update:
#   make; make print-cargo-depends > cargo-depends.mk && make distinfo
.include "cargo-depends.mk"

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
RUST_REQ=	1.51.0
.include "../../lang/rust/cargo.mk"
PYTHON_VERSIONED_DEPENDENCIES+=	OpenSSL
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
