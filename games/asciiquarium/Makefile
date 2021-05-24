# $NetBSD: Makefile,v 1.14 2021/05/24 19:52:15 wiz Exp $
#

DISTNAME=	asciiquarium_1.1
PKGNAME=	asciiquarium-1.1
PKGREVISION=	6
CATEGORIES=	games
MASTER_SITES=	https://robobunny.com/projects/asciiquarium/

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://robobunny.com/projects/asciiquarium/html/
COMMENT=	ASCII art aquarium
LICENSE=	gnu-gpl-v2

DEPENDS+=	p5-Term-Animation-[0-9]*:../../devel/p5-Term-Animation

USE_LANGUAGES=		# none
USE_TOOLS+=		perl:run
NO_BUILD=		yes
REPLACE_PERL+=		asciiquarium
INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/asciiquarium ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
