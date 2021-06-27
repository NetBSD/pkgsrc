# $NetBSD: Makefile,v 1.12 2021/06/27 07:09:56 nia Exp $
#

VER=		0.16.21
DISTNAME=	dev86-${VER}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=lkundrak/}
GITHUB_TAG=	v${VER}

MAINTAINER=	pierrick@bs-network.net
HOMEPAGE=	https://www.debath.co.uk/
COMMENT=	C compiler, assembler and linker for 8086 executables
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

CONFLICTS=	bcc-[0-9]*
CONFLICTS+=	bin86-[0-9]*

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

DESTDIR_VARNAME=	DIST

.include "../../mk/bsd.pkg.mk"
