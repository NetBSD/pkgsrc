# $NetBSD: builtin.mk,v 1.1.1.1 2004/11/27 13:01:16 jdolecek Exp $

.include "../../lang/php/phpversion.mk"

.if ${_PHP_VERSION} < 5
IS_BUILTIN.pear-netsmtp=	yes
.else
IS_BUILTIN.pear-netsmtp=	no
.endif

USE_BUILTIN.pear-netsmtp?=	${IS_BUILTIN.pear-netsmtp}

BUILDLINK_VARS+=        IS_BUILTIN.netsmtp
