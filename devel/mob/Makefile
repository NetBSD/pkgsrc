# $NetBSD: Makefile,v 1.114 2026/02/24 08:45:25 bsiegert Exp $

DISTNAME=		mob-5.4.1
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=remotemobprogramming/}
GITHUB_TAG=		${PKGVERSION_NOREV}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://mob.sh/
COMMENT=		Swift git handover during remote mob programming
LICENSE=		mit

DEPENDS+=		xdg-utils-[0-9]*:../../misc/xdg-utils

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${LN} -s mob ensemble

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
