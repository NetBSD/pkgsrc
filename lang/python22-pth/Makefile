# $NetBSD: Makefile,v 1.10 2004/01/24 08:13:14 grant Exp $
#

PKGNAME=	python22-pth-2.2.3

PTHREAD_OPTS=	require
.include "../../mk/pthread.buildlink2.mk"
.if ${PTHREAD_TYPE} == "pth"
CONFIGURE_ARGS+=	--with-pth
.endif

PY_VER_SUFFIX=	2p2

.include "../../lang/python22/Makefile.common"
