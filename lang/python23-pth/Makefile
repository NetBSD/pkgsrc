# $NetBSD: Makefile,v 1.26 2004/06/15 14:26:34 grant Exp $
#

PKGNAME=	python23-pth-2.3.4

#PKG_INSTALLATION_TYPES=	overwrite pkgviews

PTHREAD_OPTS=   require
.include "../../mk/pthread.buildlink3.mk"
.if ${PTHREAD_TYPE} == "pth"
CONFIGURE_ARGS+=	--with-pth
.endif

PY_VER_SUFFIX=	2p3

.include "../../lang/python23/Makefile.common"
