# $NetBSD: Makefile,v 1.9 2016/02/14 03:06:35 mef Exp $
#

VER=		0.16.21
DISTNAME=	dev86-${VER}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=lkundrak/}
GITHUB_TAG=	v${VER}

MAINTAINER=	pierrick@bs-network.net
HOMEPAGE=	http://www.debath.co.uk/
COMMENT=	Linux 8086 development environment
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

CONFLICTS=	bcc-[0-9]*
CONFLICTS+=	bin86-[0-9]*

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

DESTDIR_VARNAME=	DIST

.include "../../mk/bsd.pkg.mk"
