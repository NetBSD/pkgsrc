# $NetBSD: Makefile,v 1.9 2021/05/29 23:28:36 khorben Exp $

DISTNAME=	${GITHUB_PROJECT}-0.81
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=merces/}
GITHUB_PROJECT=	pev
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://pev.sourceforge.io/
COMMENT=	The PE analysis toolkit
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake

.include "../../mk/bsd.prefs.mk"

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	prefix=${PREFIX}
MAKE_FLAGS+=	mandir=${PREFIX}/${PKGMANDIR}

.include "../../security/libpe/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
