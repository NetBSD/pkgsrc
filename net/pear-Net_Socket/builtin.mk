# $NetBSD: builtin.mk,v 1.3 2004/11/27 14:16:39 jdolecek Exp $

.include "../../lang/php/phpversion.mk"

.if ${_PHP_VERSION} <= 4
IS_BUILTIN.pear-netsocket=	yes
. if defined(PEAR_NETSOCKET_VERSION_REQD) \
	&& !empty(PEAR_NETSOCKET_VERSION_REQD:M1.0.2)
# need Net_Socket 1.0.2
DEPENDS+=		php>=4.3.9nb2:../../www/php4
.  endif
.else
IS_BUILTIN.pear-netsocket=	no
.endif

USE_BUILTIN.pear-netsocket?=	${IS_BUILTIN.pear-netsocket}

BUILDLINK_VARS+=        IS_BUILTIN.pear-netsocket
