# $NetBSD: Makefile,v 1.5 2006/02/05 23:10:08 joerg Exp $
#

DISTNAME=		getopt-1.1.3
PKGREVISION=		1
CATEGORIES=		misc
MASTER_SITES=		http://www.frodol.dds.nl/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.frodol.dds.nl/
COMMENT=		Program to help shell scripts parse command-line parameters

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		gmake

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/getopt ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/getopt.1 ${PREFIX}/man/man1

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
