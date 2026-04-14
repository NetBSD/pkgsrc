# $NetBSD: Makefile,v 1.1 2026/04/14 09:49:28 kikadf Exp $

DISTNAME=		libsfdo-0.1.4
CATEGORIES=		devel
MASTER_SITE_GITLAB=	https://gitlab.freedesktop.org/
MASTER_SITES=		${MASTER_SITE_GITLAB:=vyivel/}
GITLAB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://gitlab.freedesktop.org/vyivel/libsfdo/
COMMENT=	Libraries which implement some of the freedesktop.org specifications
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}/libsfdo-${GITLAB_TAG}

.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
