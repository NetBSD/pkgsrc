# $NetBSD: builtin.mk,v 1.1.1.1 2004/11/01 21:36:45 jdolecek Exp $

.include "../../lang/php/phpversion.mk"

.if ${_PHP_VERSION} < 5
IS_BUILTIN.pear-netsocket=	yes
.else
IS_BUILTIN.pear-netsocket=	no
.endif

USE_BUILTIN.pear-netsocket?=	${IS_BUILTIN.pear-netsocket}

BUILDLINK_VARS+=        IS_BUILTIN.openssl
