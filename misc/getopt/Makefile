# $NetBSD: Makefile,v 1.15 2013/04/12 19:59:38 adam Exp $

DISTNAME=	getopt-1.1.5
CATEGORIES=	misc
MASTER_SITES=	http://software.frodo.looijaard.name/getopt/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://software.frodo.looijaard.name/getopt/
COMMENT=	Program to help shell scripts parse command-line parameters
LICENSE=	gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		gmake msgfmt

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/getopt ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/getopt.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
