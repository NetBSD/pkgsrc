# $NetBSD: Makefile,v 1.10 2004/01/24 07:09:15 grant Exp $
#

PKGNAME=	python21-pth-2.1.3
PKGREVISION=	3

PTHREAD_OPTS=	require
.include "../../mk/pthread.buildlink2.mk"
.if ${PTHREAD_TYPE} == "pth"
CONFIGURE_ARGS+=	--with-pth
.endif

PY_VER_SUFFIX=	2p1

.include "../../lang/python21/Makefile.common"
