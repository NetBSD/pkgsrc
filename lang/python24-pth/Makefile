# $NetBSD: Makefile,v 1.1.1.1 2004/12/05 23:28:53 recht Exp $
#

PKGNAME=	python24-pth-2.4

PTHREAD_OPTS=   require
.include "../../mk/pthread.buildlink3.mk"
.if ${PTHREAD_TYPE} == "pth"
CONFIGURE_ARGS+=	--with-pth
.endif

PY_VER_SUFFIX=	2p4

.include "../../lang/python24/Makefile.common"
