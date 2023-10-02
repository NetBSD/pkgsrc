# $NetBSD: platname.mk,v 1.1 2023/10/02 20:07:14 adam Exp $

.if ${OPSYS} == "Darwin"
PY_PLATNAME=	${LOWER_OPSYS}
.elif ${OPSYS} == "IRIX"
PY_PLATNAME=	${LOWER_OPSYS:C/\..*//}
.elif ${OPSYS} == "SunOS"
PY_PLATNAME=	sunos${OS_VERSION:C/\..*//}
.elif ${OPSYS} == "HPUX"
PY_PLATNAME=	hp-ux11
.elif ${OPSYS} == "Linux"
PY_PLATNAME=	linux
.else
PY_PLATNAME=	${LOWER_OPSYS}${OS_VERSION:C/\..*//}
.endif
