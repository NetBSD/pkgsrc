# $NetBSD: Makefile,v 1.35 2021/05/24 19:54:23 wiz Exp $
#

DISTNAME=		cdif-2.14
PKGREVISION=		6
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_GITHUB:=kaz-utashiro/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/kaz-utashiro/cdif
COMMENT=		Word context diff
LICENSE=		cdif-license

USE_TOOLS+=		perl:run

NO_BUILD=		yes
INSTALLATION_DIRS=	bin

REPLACE_PERL=		${PKGBASE}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PKGBASE} ${DESTDIR}${PREFIX}/bin/cdif

.include "../../mk/bsd.pkg.mk"
