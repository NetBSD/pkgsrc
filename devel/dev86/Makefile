# $NetBSD: Makefile,v 1.10 2016/05/08 16:09:38 khorben Exp $
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

MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

DESTDIR_VARNAME=	DIST

.include "../../mk/bsd.pkg.mk"
