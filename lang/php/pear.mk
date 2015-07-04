# $NetBSD: pear.mk,v 1.24 2015/07/04 14:36:56 bsiegert Exp $
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
	http://download.pear.php.net/package/ \
	http://pear.php.net/get/
MASTER_SITES+=	${MASTER_SITE_PEAR_PACKAGE}

DIST_SUBDIR=	pear

HOMEPAGE?=	http://pear.php.net/package/${DISTNAME:C/-.*//}

DEPENDS+=	${PHP_PKG_PREFIX}-pear-[0-9]*:../../lang/pear

PEAR_CMD=	${PREFIX}/bin/pear
PEAR_LIB=	lib/php
.if ${_USE_DESTDIR} != "no"
PEAR_DESTDIR=	-P ${DESTDIR} -f
.endif

# Dynamic PLIST, generated via a helper PHP script, which use registry.
PEAR_GENERATE_PLIST=	\
	${ECHO} "@comment The following lines are automatically generated"; \
	${SETENV} PEAR_LIB=${PEAR_LIB:Q} WRKSRC=${WRKSRC:Q} TZ=UTC \
	${INSTALL_ENV} PREFIX=${PREFIX:Q} \
	${PREFIX}/bin/php -d include_path=".:${PREFIX}/lib/php" \
		-d log_errors=On -d display_errors=Off \
		-C -n ${PKGDIR}/../../lang/php/pear_plist.php;
GENERATE_PLIST+=	${PEAR_GENERATE_PLIST}

NO_BUILD=	yes

.if ${_USE_DESTDIR} != "no"
PEAR_FILES_SKIP+=	${PREFIX}/lib/php/\.channels/\.alias/.*\.txt
PEAR_FILES_SKIP+=	${PREFIX}/lib/php/\.channels/.*\.reg
PEAR_FILES_SKIP+=	${PREFIX}/lib/php/\.depdb
PEAR_FILES_SKIP+=	${PREFIX}/lib/php/\.depdblock
PEAR_FILES_SKIP+=	${PREFIX}/lib/php/\.filemap
PEAR_FILES_SKIP+=	${PREFIX}/lib/php/\.lock
CHECK_FILES_SKIP+=	${PEAR_FILES_SKIP}
.endif

post-extract:
	@cd ${WRKSRC} && ${LN} -s ${WRKDIR}/package.xml package.xml

do-install:
	cd ${WRKSRC} && ${SETENV} TZ=UTC \
		${PEAR_CMD} "install" ${PEAR_DESTDIR} -n -O package.xml || exit 1
	${RM} -f ${PEAR_FILES_SKIP:S/^/${DESTDIR}&/}

.include "../../lang/php/phpversion.mk"
.include "${PHPPKGSRCDIR}/buildlink3.mk"

.endif  # _PEAR_PACKAGE_MK
