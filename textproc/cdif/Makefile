# $NetBSD: Makefile,v 1.36 2022/06/28 11:36:08 wiz Exp $
#

DISTNAME=		cdif-2.14
PKGREVISION=		7
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
