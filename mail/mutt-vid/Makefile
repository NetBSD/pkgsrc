# $NetBSD: Makefile,v 1.1 2023/04/29 13:36:05 wiz Exp $

DISTNAME=	mutt-vid-v1.1
PKGNAME=	${DISTNAME:S/-v1/-1/}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITLAB:=protist/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/protist/mutt-vid
COMMENT=	Manage multiple sender accounts in mutt
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

USE_TOOLS+=	bash:run
REPLACE_BASH+=	mutt-vid

INSTALLATION_DIRS+=	bin share/doc/mutt-vid

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mutt-vid ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/mutt-vid

.include "../../mk/bsd.pkg.mk"
