# $NetBSD: Makefile,v 1.25 2004/06/10 10:13:06 recht Exp $
#

PKGNAME=	python23-pth-2.3.4
PKGREVISION=	1

#PKG_INSTALLATION_TYPES=	overwrite pkgviews

PTHREAD_OPTS=   require
.include "../../mk/pthread.buildlink3.mk"
.if ${PTHREAD_TYPE} == "pth"
CONFIGURE_ARGS+=	--with-pth
.endif

PY_VER_SUFFIX=	2p3

.include "../../lang/python23/Makefile.common"
