# $NetBSD: Makefile,v 1.12 2004/01/27 18:55:30 abs Exp $
#

PKGNAME=	python22-pth-2.2.3
PKGREVISION=	1

PTHREAD_OPTS=	require
.include "../../mk/pthread.buildlink3.mk"
.if ${PTHREAD_TYPE} == "pth"
CONFIGURE_ARGS+=	--with-pth
.endif

PY_VER_SUFFIX=	2p2

.include "../../lang/python22/Makefile.common"
