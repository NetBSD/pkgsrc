# $NetBSD: pypi.mk,v 1.3 2016/06/01 12:39:40 wiz Exp $
#
# pypi.python.org master site handling
#
# To use, set in the pkgsrc Makefile:
#
# DISTNAME=	pyfoo-1.0.0
# MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyfoo/}
#
# Then, PKGNAME and HOMEPAGE will be set automatically (can be overridden).
#
# Keywords: pypi python

.if defined(MASTER_SITES) && !empty(MASTER_SITES:C,^https:\/\/pypi.python.org\/packages\/source\/$,match,:Mmatch)
_USE_PYPI=		YES
.endif

.if defined(_USE_PYPI) && !defined(DISTNAME)
PKG_FAIL_REASON+=	"DISTNAME must be set when MASTER_SITES = MASTER_SITE_PYPI."
.endif

.if defined(_USE_PYPI) && !empty(_USE_PYPI:MYES)
_PYPI_DEFAULT_DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

# For: https://pypi.python.org/packages/source/p/pyfoo/
_PYPI_PACKAGE_PATH=		${DISTNAME:S/-${PKGVERSION_NOREV}//1}

# For: https://pypi.python.org/packages/source/p/
_PYPI_PATH_INDEX=		${_PYPI_PACKAGE_PATH:C/^([[:alnum:]]{1}).*$/\1/1}

SITES.${_PYPI_DEFAULT_DISTFILES}=	${MASTER_SITES:=${_PYPI_PATH_INDEX}/${_PYPI_PACKAGE_PATH}/}

# Lets us override PKGNAME in the pkgsrc Makefile if necessary.
# No need to sacrifice convenience otherwise.
.if defined(PKGNAME) && ${PKGNAME} == ${DISTNAME}
PKGNAME=			${PYPKGPREFIX}-${DISTNAME}
.endif

# Makes: https://pypi.python.org/pypi/pyfoo/1.0.0 and saves an HTTP redirect.
HOMEPAGE?=			https://pypi.python.org/pypi/${_PYPI_PACKAGE_PATH}
.endif
