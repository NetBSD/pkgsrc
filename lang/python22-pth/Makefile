# $NetBSD: Makefile,v 1.13 2004/04/23 01:25:09 danw Exp $
#

PKGNAME=	python22-pth-2.2.3
PKGREVISION=	2

PTHREAD_OPTS=	require
.include "../../mk/pthread.buildlink3.mk"
.if ${PTHREAD_TYPE} == "pth"
CONFIGURE_ARGS+=	--with-pth
.endif

PY_VER_SUFFIX=	2p2

.include "../../lang/python22/Makefile.common"
