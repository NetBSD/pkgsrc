# $NetBSD: Makefile,v 1.1 2023/06/06 04:17:39 schmonz Exp $

DISTNAME=		cvs-for-gits-20230606
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=schmonz/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://github.com/schmonz/cvs-for-gits/
COMMENT=		Make CVS a bit more Gittish
LICENSE=		unlicense

DEPENDS+=		colordiff-[0-9]*:../../devel/colordiff
.if !exists(/usr/bin/less)
DEPENDS+=		less-[0-9]*:../../misc/less
.endif

USE_LANGUAGES=		# none
REPLACE_SH=		${PKGBASE}
NO_BUILD=		yes

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PKGBASE} ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
