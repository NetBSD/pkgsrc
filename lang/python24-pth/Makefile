# $NetBSD: Makefile,v 1.1.1.1.2.2 2005/02/20 18:38:38 salo Exp $
#

PKGNAME=	python24-pth-2.4
PKGREVISION=	5

PTHREAD_OPTS=   require
.include "../../mk/pthread.buildlink3.mk"
.if ${PTHREAD_TYPE} == "pth"
CONFIGURE_ARGS+=	--with-pth
.endif

PY_VER_SUFFIX=	2p4

.include "../../lang/python24/Makefile.common"
