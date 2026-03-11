# $NetBSD: Makefile,v 1.130 2026/03/11 23:22:35 gdt Exp $

DISTNAME=	matrix-synapse-1.149.1
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=element-hq/}
GITHUB_PROJECT=	synapse
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	gdt@NetBSD.org
#MAINTAINER+=	js@NetBSD.org
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
# Upstream documents that setuptools_rust is needed if you choose to
# use poetry instead of the documented/specified maturin (people that
# work on synapse does that because something is more convenient).
# However, it is coded as a depdendency for everyone, and ends up in
# METAINFO.  Experimentally, synapse starts and runs fine without it,
# so we omit it as a pkgsrc dependency.
#DEPENDS+=	${PYPKGPREFIX}-setuptools-rust>=1.3:../../devel/py-setuptools-rust
DEPENDS+=	${PYPKGPREFIX}-python-multipart>=0.0.9:../../www/py-python-multipart

# Upstream lists "transitive dependency constraints".  These are
# workarounds for bugs in other packaging systems, a bug in pip (that
# it is most of a package manager but not really in that it can't
# patch bugs in older versions while also being content to let older
# versions be), where some package A that synapse uses was released
# with a dependency on B>=n, when either B=n is just actually buggy,
# or A's use of B=n is buggy.  Really, the right fix is to have new
# enough B without bugs, or a fixed A, and this isn't about synapse.
# However, synapse forces these deps in pyproject.toml to defend its
# issue tracker from incorrect reports "synapse doesn't work right
# when I use it with buggy dependencies".
#
# For the most part, pkgsrc takes a different approach, updating
# things that are buggy, so this is not relevant.  synapse's list is
#
# cffi > 1.15
# pynacl >= 1.3
# pyparsing >= 2.4
# pyrsistent >= 0.18.0
# requests >= 2.16.0
# urllib3 >= 1.26.5
# zope-interface >= 5.2
#
# And we decline to add those here, as noise.
#
# However, pyrsistent is in pyproject.toml because jsonschema used to
# require it (before 4.18.0) -- and now it doesn't.  Without an
# explicit pkgsrc dep on pyrsistent, it isn't pulled in.  That would
# be fine, except that it appears in METAINFO (because of presence in
# pyproject.toml) and synapse then fails to start.  Reported upstream
# 20260226.
DEPENDS+=	${PYPKGPREFIX}-pyrsistent>=0.18.0:../../devel/py-pyrsistent

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
