# $NetBSD: Makefile,v 1.1 2024/01/19 15:57:59 schmonz Exp $

DISTNAME=		mlog-0.1
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GITHUB:=leahneukirchen/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://github.com/leahneukirchen/mlog/
COMMENT=		Merge log files by timestamp
LICENSE=		public-domain

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	cd ${WRKSRC}; \
	${INSTALL_PROGRAM} ${PKGBASE} ${DESTDIR}${PREFIX}/bin/; \
	${INSTALL_DATA} ${PKGBASE}.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
