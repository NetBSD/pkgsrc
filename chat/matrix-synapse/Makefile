# $NetBSD: Makefile,v 1.127 2026/02/26 14:19:48 gdt Exp $

DISTNAME=	matrix-synapse-1.148.0
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=element-hq/}
GITHUB_PROJECT=	synapse
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	js@NetBSD.org
#MAINTAINER+=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/element-hq/synapse/
COMMENT=	Reference homeserver for the Matrix decentralised comms protocol
LICENSE=	gnu-agpl-v3

# \todo Verify.
USE_LANGUAGES=		c
USE_CC_FEATURES=	c99

# Dependency management in synapse is quite troubled, with a
# pyproject.toml that is often confusing and sometimes wrong.  This
# list attempts to follow the order and contents.

.include "../../lang/python/pyversion.mk"

# Build tools:
TOOL_DEPENDS+=	${PYPKGPREFIX}-maturin>=1.0:../../devel/py-maturin
# poetry is used for some dev things, but not for building, despite
# the comments in pyproject.toml.

# Dependencies as expressed in pyproject.toml
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=3.0.0:../../textproc/py-jsonschema
# This is wrong upstream; jsonschema built with old rpds is buggy, and synapse doesn't use rpds.
DEPENDS+=	${PYPKGPREFIX}-rpds-py>=0.25.0:../../devel/py-rpds-py
DEPENDS+=	${PYPKGPREFIX}-immutabledict>=2.0:../../devel/py-immutabledict
DEPENDS+=	${PYPKGPREFIX}-unpaddedbase64>=2.1.0:../../devel/py-unpaddedbase64
DEPENDS+=	${PYPKGPREFIX}-canonicaljson>=2.0.0:../../devel/py-canonicaljson
DEPENDS+=	${PYPKGPREFIX}-signedjson>=1.1.0:../../security/py-signedjson
DEPENDS+=	${PYPKGPREFIX}-service_identity>=18.1.0:../../security/py-service_identity
DEPENDS+=	${PYPKGPREFIX}-twisted>=21.2.0:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-treq>=21.5.0:../../devel/py-treq
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=16.2.0:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.3:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-asn1>=0.1.9:../../security/py-asn1
DEPENDS+=	${PYPKGPREFIX}-asn1-modules>=0.0.7:../../security/py-asn1-modules
DEPENDS+=	${PYPKGPREFIX}-bcrypt>=3.1.7:../../security/py-bcrypt
DEPENDS+=	${PYPKGPREFIX}-Pillow>=10.0.1:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-sortedcontainers>=2.0.5:../../devel/py-sortedcontainers
DEPENDS+=	${PYPKGPREFIX}-macaroons>=0.13.0:../../devel/py-macaroons
DEPENDS+=	${PYPKGPREFIX}-msgpack>=0.5.2:../../devel/py-msgpack
DEPENDS+=	${PYPKGPREFIX}-phonenumbers>=8.2.0:../../textproc/py-phonenumbers
DEPENDS+=	${PYPKGPREFIX}-prometheus_client>=0.6.0:../../net/py-prometheus_client
# To avoid the !=21.1.0, we just require 21.1.1 or newer.
DEPENDS+=	${PYPKGPREFIX}-attrs>=21.1.1:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-netaddr>=0.7.18:../../net/py-netaddr
DEPENDS+=	${PYPKGPREFIX}-jinja2>=3.0:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-bleach>=3.2.0:../../www/py-bleach
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.14.1:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-cryptography>=3.4.7:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-ijson>=3.1.4:../../devel/py-ijson
DEPENDS+=	${PYPKGPREFIX}-matrix-common>=1.3.0:../../chat/py-matrix-common
DEPENDS+=	${PYPKGPREFIX}-packaging>=20.0:../../devel/py-packaging
# If py<3.14, only need 2.8, but just require >=2.12 to simplify.
DEPENDS+=	${PYPKGPREFIX}-pydantic>=2.12:../../devel/py-pydantic
# Upstream documents that this is needed for poetry, but the
# explanation is very confusing.
#DEPENDS+=	${PYPKGPREFIX}-setuptools-rust>=1.3:../../devel/py-setuptools-rust
DEPENDS+=	${PYPKGPREFIX}-python-multipart>=0.0.9:../../www/py-python-multipart

# Upstream does NOT document a dependency on pyrsistent, but synapse
# crashes if it is not present, because it ends up in
# /usr/pkg/lib/python3.13/site-packages/matrix_synapse-1.146.0.dist-info/METADATA
# The version is taken from METADATA.  However, I can find no actual usage.
#
# A separate issue is that upstream claims pyrsistent is required via
# jsonschema, but the pkgsrc jsonschema package and its pyproject.toml
# do not reference pyrsistent at all.
DEPENDS+=	${PYPKGPREFIX}-pyrsistent>=0.18.0:../../devel/py-pyrsistent

# Upstream lists "transitive dependency constraints". The theory is
# that they are required by something that synapse depends on, and
# that synapse doesn't actually use them.  Yet somehow, a version that
# is older than the one listed here, but new enough for the other
# required package, will somehow cause that package to misbehave when
# used by synapse.
# We ignore this for now, as a quantum superposition of not making
# sense and it being likely the pkgsrc versions are adequately up to
# date.

# cffi > 1.15
# pynacl >= 1.3
# pyparsing >= 2.4
# pyrsistent >= 0.18.0
# requests >= 2.16.0
# urllib3 >= 1.26.5
# zope-interface >= 5.2

## OPTIONS
#
# For each, we either just require the dependencies so all synapse
# builds have the option, require none so the builds don't, or turn it
# into a real option.

# matrix-synapse-ldap3: \todo

# postgres: always on
# In theory, one could use sqlite3 and argue that this should be an
# option.  The package chooses to always support pgsql as the standard
# database approach for synapse.
DEPENDS+=	${PYPKGPREFIX}-psycopg2>=2.8:../../databases/py-psycopg2

# saml2: see options.mk

# oidc: always on
DEPENDS+=	${PYPKGPREFIX}-authlib>=0.15.1:../../security/py-authlib

# systemd: never

# url-preview: always on
DEPENDS+=	${PYPKGPREFIX}-lxml>=4.6.3:../../textproc/py-lxml

# sentry: never

# opentracing: never

# jwt: ignored, but same dep as oidc, with no version requirement

# redis: \todo

# cache-memory: \todo

# test: enabled when testing
TEST_DEPENDS+=	${PYPKGPREFIX}-parameterized>=0.9.0:../../devel/py-parameterized
TEST_DEPENDS+=	${PYPKGPREFIX}-idna>=3.3:../../www/py-idna

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

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} files/README.pkgsrc.txt ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} files/README.pkgsrc.NetBSD.txt ${DESTDIR}${DOCDIR}
	# upstream incorrectly includes .orig files in the wheel.
	# Because the wheel is built during the build phase, not the
	# install phase, a pre-install target to clean them up in the
	# sources does not work.  Cleaning them up earlier breaks
	# mkpatches.
	cd ${DESTDIR} && find . -name '*.orig' | xargs rm

# \todo Grok upstream's new test scheme and port to it.
# As of 1.98.0 all tests fail, most of them failing to import
# synapse.synapse_rust.
# Quick fix before running tests: rm -r ${WRKSRC}/synapse

# New upstream releases typically add/change cargo depends.
.PHONY: update-cargo
update-cargo:
	make extract && make print-cargo-depends > cargo-depends.mk && make distinfo

.include "cargo-depends.mk"

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
RUST_REQ=	1.51.0
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
