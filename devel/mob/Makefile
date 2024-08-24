# $NetBSD: Makefile,v 1.96 2024/08/24 18:28:40 schmonz Exp $

DISTNAME=		mob-5.1.0
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=remotemobprogramming/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://mob.sh/
COMMENT=		Swift git handover during remote mob programming
LICENSE=		mit

DEPENDS+=		xdg-utils-[0-9]*:../../misc/xdg-utils

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${LN} -s mob ensemble

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
