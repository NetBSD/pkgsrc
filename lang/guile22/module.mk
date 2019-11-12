# $NetBSD: module.mk,v 1.1 2019/11/12 12:41:19 ng0 Exp $
#
# Common build logic for Guile 2.2 modules using gnu configure.
#
# === Package-settable-variables ===
#
# GUILE_NEED_BOOTSTRAP
#	Whether the package requires a bootstrap run of autotools
# 	or not.
#
#	Possible values: yes no

.if defined(GNU_CONFIGURE)
GNU_CONFIGURE_PREFIX=	${PREFIX}/guile/2.2
CONFIGURE_ARGS+=	--libdir=${PREFIX}/guile/2.2/lib

.if defined(GUILE_NEED_BOOTSTRAP)
USE_TOOLS+=		automake autoconf autoreconf
pre-configure:
	(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} autoreconf -I${PREFIX}/guile/2.2/share/aclocal -vif)
.endif

.include "../../lang/guile22/buildlink3.mk"
.endif
