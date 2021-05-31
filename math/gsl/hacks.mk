# $NetBSD: hacks.mk,v 1.2 2021/05/31 10:35:17 wiz Exp $

.include "../../mk/compiler.mk"

### [Mon Feb 28 12:11:29 2005 UTC : dmcmahill]
### At least gcc-3.3.5 failed to compile gsl-1.6/statistics/lag1.c
### with -mcpu=v9 on a solaris/sparc system.
###
.if (${OPSYS} == "SunOS") && ${MACHINE_ARCH} == sparc && \
    !empty(CC_VERSION:M*gcc*)
PKG_HACKS+=		solaris-sparc-ice
BUILDLINK_TRANSFORM+=	rm:-mcpu=v9
.endif
