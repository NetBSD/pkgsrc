# $NetBSD: Makefile,v 1.21 2004/04/23 01:25:09 danw Exp $
#

PKGNAME=	python23-pth-2.3.3
PKGREVISION=	3

PTHREAD_OPTS=   require
.include "../../mk/pthread.buildlink3.mk"
.if ${PTHREAD_TYPE} == "pth"
CONFIGURE_ARGS+=	--with-pth
.endif

PY_VER_SUFFIX=	2p3

.include "../../lang/python23/Makefile.common"
