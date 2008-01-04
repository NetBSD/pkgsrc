# $NetBSD: Makefile,v 1.9 2008/01/04 07:18:21 obache Exp $
#

DISTNAME=		getopt-1.1.3
PKGREVISION=		1
CATEGORIES=		misc
MASTER_SITES=		http://software.frodo.looijaard.name/getopt/files/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://software.frodo.looijaard.name/getopt/
COMMENT=		Program to help shell scripts parse command-line parameters

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		gmake

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/getopt ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/getopt.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
