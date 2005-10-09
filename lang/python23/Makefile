# $NetBSD: Makefile,v 1.29.2.1 2005/10/09 00:17:41 salo Exp $
#

PKGNAME=	python23-2.3.5
PKGREVISION=	3

CONFLICTS+=	python-[0-9]*

#PKG_INSTALLATION_TYPES=	overwrite pkgviews

PTHREAD_OPTS=   require
.include "../../mk/pthread.buildlink3.mk"
.if ${PTHREAD_TYPE} == "pth"
CONFIGURE_ARGS+=	--with-pth
.endif

PY_VER_SUFFIX=	2.3

.include "../../lang/python23/Makefile.common"
