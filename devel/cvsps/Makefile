# $NetBSD: Makefile,v 1.29 2021/02/09 06:22:45 adam Exp $

DISTNAME=	cvsps-2.1
PKGREVISION=	4
CATEGORIES=	devel scm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cvsps/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://cvsps.sourceforge.net/
COMMENT=	Generates 'patchset' information from a CVS repository
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

LIBS.SunOS+=		-lnsl -lsocket
MAKE_ENV+=		LIBS=${LIBS:M*:Q}
MAKE_ENV+=		prefix=${DESTDIR}${PREFIX}

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
