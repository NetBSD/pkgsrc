# $NetBSD: Makefile,v 1.1 2013/01/30 11:34:58 ryoon Exp $
#

DISTNAME=	cvsps-3.2
PKGNAME=	${DISTNAME:S/cvsps-/cvsps3-/}
CATEGORIES=	devel scm
MASTER_SITES=	${HOMEPAGE:Q}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://www.catb.org/~esr/cvsps/
COMMENT=	Generates 'patchset' information from a CVS repository
LICENSE=	gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		gmake

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

LIBS.SunOS+=		-lnsl -lsocket
MAKE_ENV+=		LIBS=${LIBS:Q}
MAKE_ENV+=		prefix=${DESTDIR}${PREFIX}

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
