# $NetBSD: Makefile,v 1.5 2016/07/15 11:17:04 mef Exp $

VERSION=	0.4.0
DISTNAME=	cwdiff-${VERSION}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=junghans/}
GITHUB_TAG=	v${VERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/junghans/cwdiff
COMMENT=	Color wrapper for wdiff (word diff)
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	bash
NO_BUILD=	yes
REPLACE_BASH=	cwdiff

INSTALLATION_DIRS+=	share/examples/cwdiff/
AUTO_MKDIRS=	yes

do-install:
	(cd ${WRKSRC} ;\
	${INSTALL_SCRIPT} cwdiff          ${DESTDIR}${PREFIX}/bin ;\
	${INSTALL_DATA} cwdiff.rc  ${DESTDIR}${PREFIX}/${INSTALLATION_DIRS} ;\
	)

.include "../../mk/bsd.pkg.mk"
