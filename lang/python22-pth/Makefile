# $NetBSD: Makefile,v 1.14.4.1 2005/02/16 14:00:08 salo Exp $
#

PKGNAME=	python22-pth-2.2.3
PKGREVISION=	5

PTHREAD_OPTS=	require
.include "../../mk/pthread.buildlink3.mk"
.if ${PTHREAD_TYPE} == "pth"
CONFIGURE_ARGS+=	--with-pth
.endif

PY_VER_SUFFIX=	2p2

.include "../../lang/python22/Makefile.common"
