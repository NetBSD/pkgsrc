# $NetBSD: Makefile,v 1.1.1.1 2004/12/26 15:55:39 wiz Exp $
#

DISTNAME=		getopt-1.1.3
CATEGORIES=		misc
MASTER_SITES=		http://www.frodol.dds.nl/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.frodol.dds.nl/
COMMENT=		Program to help shell scripts parse command-line parameters

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/getopt ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/getopt.1 ${PREFIX}/man/man1

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
