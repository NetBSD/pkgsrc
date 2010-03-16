# $NetBSD: pear.mk,v 1.18 2010/03/16 15:34:01 taca Exp $
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
.if ${_USE_DESTDIR} != "no"
PEAR_DESTDIR=	-P ${DESTDIR} -n -f
.endif

# Dynamic PLIST, generated via a helper PHP script, which parses the package
# XML config file.
PEAR_GENERATE_PLIST=	\
	${ECHO} "@comment The following lines are automatically generated"; \
	PEAR_LIB="${PEAR_LIB}" WRKSRC="${WRKSRC}" \
	${PREFIX}/bin/php -d include_path=".:${PREFIX}/lib/php" \
		-C -n ${PKGDIR}/../../lang/php/pear_plist.php;
GENERATE_PLIST+=	${PEAR_GENERATE_PLIST}

NO_BUILD=	yes

post-extract:
	@cd ${WRKSRC} && ${LN} -s ${WRKDIR}/package.xml package.xml

do-install:
	cd ${WRKSRC} && ${SETENV} TZ=UTC \
		${PEAR_CMD} "install" ${PEAR_DESTDIR} package.xml || exit 1

.if ${_USE_DESTDIR} != "no"
CHECK_FILES_SKIP+=	${PREFIX}/lib/php/.channels/.alias/phpdocs.txt
CHECK_FILES_SKIP+=	${PREFIX}/lib/php/.channels/.alias/pear.txt
CHECK_FILES_SKIP+=	${PREFIX}/lib/php/.channels/.alias/pecl.txt
CHECK_FILES_SKIP+=	${PREFIX}/lib/php/.channels/__uri.reg
CHECK_FILES_SKIP+=	${PREFIX}/lib/php/.channels/doc.php.net.reg
CHECK_FILES_SKIP+=	${PREFIX}/lib/php/.channels/pear.php.net.reg
CHECK_FILES_SKIP+=	${PREFIX}/lib/php/.channels/pecl.php.net.reg
CHECK_FILES_SKIP+=	${PREFIX}/lib/php/.depdb
CHECK_FILES_SKIP+=	${PREFIX}/lib/php/.depdblock
CHECK_FILES_SKIP+=	${PREFIX}/lib/php/.filemap
CHECK_FILES_SKIP+=	${PREFIX}/lib/php/.lock
.endif

.include "../../lang/php/phpversion.mk"
.include "${PHPPKGSRCDIR}/buildlink3.mk"

.endif  # _PEAR_PACKAGE_MK
