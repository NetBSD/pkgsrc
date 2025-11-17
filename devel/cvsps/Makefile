# $NetBSD: Makefile,v 1.30 2025/11/17 11:00:34 wiz Exp $

DISTNAME=	cvsps-2.1
PKGREVISION=	4
CATEGORIES=	devel scm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cvsps/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://cvsps.sourceforge.net/
COMMENT=	Generates 'patchset' information from a CVS repository
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

LIBS.SunOS+=		-lnsl -lsocket
MAKE_ENV+=		LIBS=${LIBS:M*:Q}
MAKE_ENV+=		prefix=${DESTDIR}${PREFIX}

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
