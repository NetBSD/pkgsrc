# $NetBSD: Makefile,v 1.18 2004/01/27 18:55:30 abs Exp $
#

PKGNAME=	python23-pth-2.3.3
PKGREVISION=	1

PTHREAD_OPTS=   require
.include "../../mk/pthread.buildlink2.mk"
.if ${PTHREAD_TYPE} == "pth"
CONFIGURE_ARGS+=	--with-pth
.endif

PY_VER_SUFFIX=	2p3

.include "../../lang/python23/Makefile.common"
