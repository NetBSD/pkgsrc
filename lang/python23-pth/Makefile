# $NetBSD: Makefile,v 1.17 2004/01/25 21:10:11 recht Exp $
#

PKGNAME=	python23-pth-2.3.3

PTHREAD_OPTS=   require
.include "../../mk/pthread.buildlink2.mk"
.if ${PTHREAD_TYPE} == "pth"
CONFIGURE_ARGS+=	--with-pth
.endif

PY_VER_SUFFIX=	2p3

.include "../../lang/python23/Makefile.common"
