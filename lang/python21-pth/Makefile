# $NetBSD: Makefile,v 1.11 2004/01/25 16:06:47 recht Exp $
#

PKGNAME=	python21-pth-2.1.3
PKGREVISION=	3

PTHREAD_OPTS=	require
.include "../../mk/pthread.buildlink3.mk"
.if ${PTHREAD_TYPE} == "pth"
CONFIGURE_ARGS+=	--with-pth
.endif

PY_VER_SUFFIX=	2p1

.include "../../lang/python21/Makefile.common"
