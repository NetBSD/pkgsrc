# $NetBSD: Makefile,v 1.4 2006/01/24 07:32:05 wiz Exp $
#

DISTNAME=		kdissert-1.0.5
PKGREVISION=		1
CATEGORIES=		editors
MASTER_SITES=		http://freehackers.org/~tnagy/kdissert/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://freehackers.org/~tnagy/kdissert/
COMMENT=		Mindmapping-like tool to generate text templates

USE_PKGLOCALEDIR=	yes
NO_CONFIGURE=		yes

BUILD_DEPENDS+=	scons>=0.96.1nb1:../../devel/scons

do-build:
	${_PKG_SILENT}${_PKG_DEBUG}${_ULIMIT_CMD}cd ${WRKSRC} \
		&& ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/scons

do-install:
	${_PKG_SILENT}${_PKG_DEBUG}${_ULIMIT_CMD}cd ${WRKSRC} \
		&& ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/scons install

.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
