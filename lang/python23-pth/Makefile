# $NetBSD: Makefile,v 1.23 2004/05/12 16:25:34 recht Exp $
#

PKGNAME=	python23-pth-2.3.3
PKGREVISION=	4

#PKG_INSTALLATION_TYPES=	overwrite pkgviews

PTHREAD_OPTS=   require
.include "../../mk/pthread.buildlink3.mk"
.if ${PTHREAD_TYPE} == "pth"
CONFIGURE_ARGS+=	--with-pth
.endif

PY_VER_SUFFIX=	2p3

.include "../../lang/python23/Makefile.common"
