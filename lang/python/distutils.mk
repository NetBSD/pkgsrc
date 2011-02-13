# $NetBSD: distutils.mk,v 1.2 2011/02/13 08:09:43 obache Exp $
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
# this norm and will work with all python versions.  (If the package
# set PY_NO_EGG, respect that choice, but PLIST.eggfile is still set.)

# Set the egg file basename.
EGG_NAME?=	${DISTNAME}

PLIST_VARS+=	eggfile
.if !empty(PYDISTUTILS_CREATES_EGGFILES:M[yY][eE][sS])
# Python distutils will create an eggfile.
PLIST.eggfile=	yes
PY_NO_EGG?=	no
.else
# Python distutils will not create an eggfile.
# (PLIST.eggfile being set to no is equivalent to being set to yes!)
PY_NO_EGG?=	yes
.endif

# Egg files have the version encoded, so generalize in PLIST, and provide
# our conditional.
PLIST_SUBST+=	EGG_FILE=${EGG_NAME}-py${PYVERSSUFFIX}.egg-info
# PYSITELIB is already de-expanded
PRINT_PLIST_AWK+=	{ gsub("[$$]{PYSITELIB}/${EGG_NAME}-py${PYVERSSUFFIX}.egg-info", \
				"$${PLIST.eggfile}$${PYSITELIB}/$${EGG_FILE}") }

.include "../../lang/python/extension.mk"
