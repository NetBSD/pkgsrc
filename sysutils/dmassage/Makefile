# $NetBSD: Makefile,v 1.1.1.1 2004/06/07 17:42:12 xtraeme Exp $
#

DISTNAME=	dmassage-0.6
CATEGORIES=	sysutils
MASTER_SITES=	http://www.sentia.org/downloads/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.sentia.org/projects/dmassage/
COMMENT=	dmesg(8) parser

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_BUILD=	yes
USE_PERL5=	run
REPLACE_PERL=	dmassage

INSTALLATION_DIRS=	bin share/doc/${PKGBASE}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dmassage ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/${PKGBASE}

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
