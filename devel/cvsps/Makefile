# $NetBSD: Makefile,v 1.26 2014/10/09 14:06:08 wiz Exp $
#

DISTNAME=	cvsps-2.1
PKGREVISION=	3
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
