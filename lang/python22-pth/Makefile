# $NetBSD: Makefile,v 1.14 2004/08/29 10:44:19 recht Exp $
#

PKGNAME=	python22-pth-2.2.3
PKGREVISION=	3

PTHREAD_OPTS=	require
.include "../../mk/pthread.buildlink3.mk"
.if ${PTHREAD_TYPE} == "pth"
CONFIGURE_ARGS+=	--with-pth
.endif

PY_VER_SUFFIX=	2p2

.include "../../lang/python22/Makefile.common"
