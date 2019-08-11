# $NetBSD: Makefile,v 1.2 2019/08/11 13:23:18 wiz Exp $

DISTNAME=	trash-0.9.2
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=ali-rantakari/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ali-rantakari/trash/
COMMENT=	Command-line program for OS X that moves files or folders to the trash
LICENSE=	mit

ONLY_FOR_PLATFORM=	Darwin-*-*

# actually, pod2man
USE_TOOLS+=	gmake perl

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-build:
	cd ${WRKSRC} && ${GMAKE}
	cd ${WRKSRC} && ${GMAKE} docs

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/trash ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/trash.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
