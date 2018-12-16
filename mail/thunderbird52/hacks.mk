# $NetBSD: hacks.mk,v 1.1 2018/12/16 08:29:48 ryoon Exp $

# workround for link of thunderbird-bin etc.
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/${MOZILLA_NAME}

.if ${OPSYS} == "SunOS"
# workaround for strip problems with libxul.so
# https://www.illumos.org/issues/4383
INSTALL_UNSTRIPPED=yes
.endif
