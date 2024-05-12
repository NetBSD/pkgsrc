# $NetBSD: Makefile,v 1.1 2024/05/12 12:41:57 pho Exp $

DISTNAME=	ddns-route53-2.12.0
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
