# $NetBSD: Makefile,v 1.6 2006/03/04 21:29:31 jlam Exp $
#

DISTNAME=		kdissert-1.0.5
PKGREVISION=		2
CATEGORIES=		editors
MASTER_SITES=		http://freehackers.org/~tnagy/kdissert/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
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
