# $NetBSD: Makefile,v 1.6 2024/09/06 18:48:49 bsiegert Exp $

DISTNAME=	ddns-route53-2.12.0
PKGREVISION=	5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=crazy-max/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
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
