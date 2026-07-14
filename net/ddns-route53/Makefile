# $NetBSD: Makefile,v 1.21.2.1 2026/07/14 00:35:54 maya Exp $

DISTNAME=	ddns-route53-2.15.0
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=crazy-max/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://crazymax.dev/ddns-route53/
COMMENT=	Dynamic DNS for Amazon Route 53 on a time-based schedule
LICENSE=	mit

.include "go-modules.mk"

post-install:
# Don't know why but the executable is installed as "bin/cmd". Rename it.
	if ${TEST} -f "${DESTDIR}${PREFIX}/bin/cmd"; then \
		${MV} "${DESTDIR}${PREFIX}/bin/cmd" "${DESTDIR}${PREFIX}/bin/ddns-route53"; \
	fi

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
