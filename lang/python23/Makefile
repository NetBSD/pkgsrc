# $NetBSD: Makefile,v 1.26 2005/02/04 15:39:04 drochner Exp $
#

PKGNAME=	python23-2.3.4
PKGREVISION=	7

CONFLICTS+=	python-[0-9]*

#PKG_INSTALLATION_TYPES=	overwrite pkgviews

PTHREAD_OPTS=   require
.include "../../mk/pthread.buildlink3.mk"
.if ${PTHREAD_TYPE} == "pth"
CONFIGURE_ARGS+=	--with-pth
.endif

PY_VER_SUFFIX=	2.3

.include "../../lang/python23/Makefile.common"
