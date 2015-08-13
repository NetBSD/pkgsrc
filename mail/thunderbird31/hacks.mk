# $NetBSD: hacks.mk,v 1.2 2015/08/13 20:17:30 joerg Exp $

# workround for link of thunderbird-bin etc.
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/thunderbird31

.if ${OPSYS} == "SunOS"
# workaround for strip problems with libxul.so
# https://www.illumos.org/issues/4383
INSTALL_UNSTRIPPED=yes
.endif
.include "../../devel/xulrunner17/hacks.mk"
