# $NetBSD: Makefile,v 1.3 2002/12/23 08:05:34 jmmv Exp $
#

DISTNAME=	dact-0.8.3
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	http://www.rkeene.org/devel/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.rkeene.org/devel/dact/
COMMENT=	dynamic adaptive compression tool

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/dact

.include "../../archivers/bzip2/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
