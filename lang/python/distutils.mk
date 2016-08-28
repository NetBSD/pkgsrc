# $NetBSD: distutils.mk,v 1.8 2016/08/28 09:40:35 richard Exp $
#
# Common logic for python distributions that use distutils.
#
.include "../../mk/bsd.fast.prefs.mk"

.include "../../lang/python/pyversion.mk"

# This file should be included to package python "distributions" which
# use distutils.  See egg.mk for distributions that use setuptools and
# extensions.mk for ad hoc cases.

# Some day, hoist the PYDISTUTILSPKG code in extension.mk to here,
# after all distutils-using packages use this.
PYDISTUTILSPKG=	yes

# We expect distutils to create an egg-info file if Python distutils
# can do so, and provide support for a PLIST entry that represents
# this norm and will work with all python versions.

# Set the egg file basename.
EGG_NAME?=	${DISTNAME:C/-([^0-9])/_\1/g}

# Python distutils will create an eggfile.
PY_NO_EGG?=	no

# Egg files have the version encoded, so generalize in PLIST.
PLIST_SUBST+=	EGG_FILE=${EGG_NAME}-py${PYVERSSUFFIX}.egg-info
PRINT_PLIST_AWK+=	{ gsub("${EGG_NAME}-py${PYVERSSUFFIX}.egg-info", \
				"$${EGG_FILE}") }
PRINT_PLIST_AWK+=	{ gsub(/${PYVERSSUFFIX}/, \
				"$${PYVERSSUFFIX}") }

.include "../../lang/python/extension.mk"
