# $NetBSD: Makefile,v 1.19 2004/03/26 02:27:42 wiz Exp $
#

PKGNAME=	python23-pth-2.3.3
PKGREVISION=	2

PTHREAD_OPTS=   require
.include "../../mk/pthread.buildlink2.mk"
.if ${PTHREAD_TYPE} == "pth"
CONFIGURE_ARGS+=	--with-pth
.endif

PY_VER_SUFFIX=	2p3

.include "../../lang/python23/Makefile.common"
