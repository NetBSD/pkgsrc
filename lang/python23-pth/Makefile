# $NetBSD: Makefile,v 1.20 2004/04/13 22:48:41 recht Exp $
#

PKGNAME=	python23-pth-2.3.3
PKGREVISION=	2

PTHREAD_OPTS=   require
.include "../../mk/pthread.buildlink3.mk"
.if ${PTHREAD_TYPE} == "pth"
CONFIGURE_ARGS+=	--with-pth
.endif

PY_VER_SUFFIX=	2p3

.include "../../lang/python23/Makefile.common"
