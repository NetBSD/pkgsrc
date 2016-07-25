# $NetBSD: Makefile,v 1.27 2016/07/25 05:10:03 christos Exp $
#

DISTNAME=	cvsps-2.1
PKGREVISION=	4
CATEGORIES=	devel scm
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://www.cobite.com/cvsps/
COMMENT=	Generates 'patchset' information from a CVS repository
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

LIBS.SunOS+=		-lnsl -lsocket
MAKE_ENV+=		LIBS=${LIBS:M*:Q}
MAKE_ENV+=		prefix=${DESTDIR}${PREFIX}

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
