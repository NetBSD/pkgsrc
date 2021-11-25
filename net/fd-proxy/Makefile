# $NetBSD: Makefile,v 1.1 2021/11/25 08:18:18 schmonz Exp $

GITHUB_PROJECT=	fd-proxy
GITHUB_TAG=	33b844d998c32c82dcc825ab316f97a0adc2b92f
PKGVERSION=	20141025
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}-${PKGVERSION}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=wingunder/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://github.com/wingunder/fd-proxy/
COMMENT=	Glue for making a TCP proxy using ucspi-tcp tools
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${PKGBASE}-${GITHUB_TAG}

INSTALLATION_DIRS=	bin share/doc/${PKGBASE}

do-install:
	cd ${WRKSRC} && \
	${INSTALL_PROGRAM} ${PKGBASE} ${DESTDIR}${PREFIX}/bin && \
	${INSTALL_DATA} README.md ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
