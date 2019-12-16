# $NetBSD: replace.mk,v 1.1 2019/12/16 15:58:18 taca Exp $
#

.if !defined(_PHP_REPLACE_MK)
_PHP_REPLACE_MK=	# defined

.include "${.PARSEDIR}/phpversion.mk"

PHP_NAME=	php${PKG_PHP_VERSION}

# fix shebang line.
#
# REPLACE_PHP		replace shebang line of specified files.
#
.if !empty(REPLACE_PHP)
REPLACE_INTERPRETER+=	${PHP_NAME}

REPLACE.${PHP_NAME}.old=	.*php
REPLACE.${PHP_NAME}.new=	${PREFIX}/bin/php
REPLACE_FILES.${PHP_NAME}=	${REPLACE_PHP}

.endif # defined(REPLACE_PHP)

.endif # _PHP_REPLACE_MK
