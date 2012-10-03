# $NetBSD: Makefile,v 1.2 2012/10/03 21:56:04 wiz Exp $
#

DISTNAME=	asciiquarium_1.0
PKGNAME=	asciiquarium-1.0
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://robobunny.com/projects/asciiquarium/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://robobunny.com/projects/asciiquarium/html/
COMMENT=	ASCII art aquarium
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Term-Animation-[0-9]*:../../devel/p5-Term-Animation

USE_LANGUAGES=	# none
USE_TOOLS+=	perl:run
NO_BUILD=	yes
REPLACE_PERL+=	asciiquarium
INSTALLATION_DIRS+= bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/asciiquarium ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
