# $NetBSD: Makefile,v 1.14 2004/08/29 10:44:19 recht Exp $
#

PKGNAME=	python21-pth-2.1.3
PKGREVISION=	6

PTHREAD_OPTS=	require
.include "../../mk/pthread.buildlink3.mk"
.if ${PTHREAD_TYPE} == "pth"
CONFIGURE_ARGS+=	--with-pth
.endif

PY_VER_SUFFIX=	2p1

.include "../../lang/python21/Makefile.common"
