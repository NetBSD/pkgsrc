# $NetBSD: Makefile,v 1.19 2026/07/01 01:15:55 gutteridge Exp $

DISTNAME=	getopt-1.1.6
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://frodo.looijaard.name/system/files/software/getopt/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://frodo.looijaard.name/project/getopt
COMMENT=	Program to help shell scripts parse command-line parameters
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/getopt ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/getopt.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
