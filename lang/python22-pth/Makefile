# $NetBSD: Makefile,v 1.11 2004/01/25 16:06:47 recht Exp $
#

PKGNAME=	python22-pth-2.2.3

PTHREAD_OPTS=	require
.include "../../mk/pthread.buildlink3.mk"
.if ${PTHREAD_TYPE} == "pth"
CONFIGURE_ARGS+=	--with-pth
.endif

PY_VER_SUFFIX=	2p2

.include "../../lang/python22/Makefile.common"
