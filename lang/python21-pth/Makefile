# $NetBSD: Makefile,v 1.12 2004/01/27 18:55:30 abs Exp $
#

PKGNAME=	python21-pth-2.1.3
PKGREVISION=	4

PTHREAD_OPTS=	require
.include "../../mk/pthread.buildlink3.mk"
.if ${PTHREAD_TYPE} == "pth"
CONFIGURE_ARGS+=	--with-pth
.endif

PY_VER_SUFFIX=	2p1

.include "../../lang/python21/Makefile.common"
