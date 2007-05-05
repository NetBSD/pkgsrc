# $NetBSD: pear.mk,v 1.10 2007/05/05 21:32:12 adrianp Exp $
#
# This Makefile fragment is intended to be included by packages that build
# and install pear packages.
#
# If you don't know what pear is, you can visit: http://pear.php.net/
#
# PEAR_CMD	this is the actual script to execute to install the
#		package.
#
# PEAR_LIB	directory under ${PREFIX} where Pear modules are installed
#

.if !defined(_PEAR_PACKAGE_MK)
_PEAR_PACKAGE_MK=       # defined

.include "../../mk/bsd.prefs.mk"

EXTRACT_SUFX=	.tgz

PKGNAME=	${PHP_PKG_PREFIX}-pear-${DISTNAME}
CATEGORIES+=	www

MASTER_SITE_PEAR_PACKAGE+= \
	http://pear.php.net/get/
MASTER_SITES+=	${MASTER_SITE_PEAR_PACKAGE}

DIST_SUBDIR=	pear

HOMEPAGE?=	http://pear.php.net/package/${DISTNAME:C/-.*//}

DEPENDS+=	${PHP_PKG_PREFIX}-pear-[0-9]*:../../lang/pear

PEAR_CMD=	${PREFIX}/bin/pear
PEAR_LIB=	lib/php

# whether @dirrm for baseinstalldir should be included in PLIST
PEAR_DIRRM_BASEDIR?=	# empty

# Dynamic PLIST, generated via a helper PHP script, which parses the package
# XML config file.
PEAR_GENERATE_PLIST=	\
	${ECHO} "@comment The following lines are automatically generated"; \
	PEAR_LIB="${PEAR_LIB}" WRKSRC="${WRKSRC}" \
	PEAR_DIRRM_BASEDIR="${PEAR_DIRRM_BASEDIR}" \
	${PREFIX}/bin/php -d include_path=".:${PREFIX}/lib/php" \
		-C -n ${PKGDIR}/../../lang/php/pear_plist.php;
GENERATE_PLIST+=	${PEAR_GENERATE_PLIST}

NO_BUILD=	yes

post-extract:
	@cd ${WRKSRC} && ${LN} -s ${WRKDIR}/package.xml package.xml

do-install:
	cd ${WRKSRC} && ${PEAR_CMD} "install" package.xml || exit 1

.include "../../lang/php/phpversion.mk"
.include "${PHPPKGSRCDIR}/buildlink3.mk"

.endif  # _PEAR_PACKAGE_MK
