# $NetBSD: Makefile,v 1.1 2021/11/15 11:36:58 schmonz Exp $

GITHUB_PROJECT=		tcpexec
GITHUB_TAG=		7e02e755aca4cb377910b729e43de8e3fb48eece
DISTNAME=		${GITHUB_TAG}
PKGNAME=		${GITHUB_PROJECT}-0.1.1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GITHUB:=msantos/}
DIST_SUBDIR=		${GITHUB_PROJECT}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://github.com/msantos/tcpexec/
COMMENT=		Minimal UCSPI inetd
LICENSE=		isc

TEST_DEPENDS+=		bats-[0-9]*:../../devel/bats
TEST_TARGET=		test	# XXX needs to be run as root

INSTALLATION_DIRS=	bin share/doc/${PKGBASE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcpexec ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
