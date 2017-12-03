# $NetBSD: hacks.mk,v 1.1.6.1 2017/12/03 11:41:43 bsiegert Exp $

# workround for link of thunderbird-bin etc.
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/${MOZILLA_NAME}

.if ${OPSYS} == "SunOS"
# workaround for strip problems with libxul.so
# https://www.illumos.org/issues/4383
INSTALL_UNSTRIPPED=yes
.endif
