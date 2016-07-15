# $NetBSD: Makefile,v 1.3 2016/07/15 11:01:18 mef Exp $

DISTNAME=	cwdiff-0.2.7
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=junghans/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://code.google.com/p/cj-overlay/
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
	${INSTALL_DATA} hgrc.d/cwdiff.rc  ${DESTDIR}${PREFIX}/${INSTALLATION_DIRS} ;\
	)

.include "../../mk/bsd.pkg.mk"
