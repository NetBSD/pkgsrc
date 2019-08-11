# $NetBSD: Makefile,v 1.2 2019/08/11 13:22:29 wiz Exp $

DISTNAME=	rt-4.4.4
PKGNAME=	${DISTNAME:S/rt/rt4-cli/}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://download.bestpractical.com/pub/rt/release/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://www.bestpractical.com/rt/
COMMENT=	Command-line interface to RT 3.0 or newer
LICENSE=	gnu-gpl-v2

CONFLICTS+=	rt<4.0

DEPENDS+=	p5-HTTP-Message-[0-9]*:../../www/p5-HTTP-Message
DEPENDS+=	p5-Term-ReadKey-[0-9]*:../../devel/p5-Term-ReadKey
DEPENDS+=	p5-Term-ReadLine-[0-9]*:../../devel/p5-Term-ReadLine
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

USE_TOOLS+=	perl:run

NO_BUILD=	yes

USE_LANGUAGES=	# none

REPLACE_PERL+=	bin/rt

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/rt ${DESTDIR}${PREFIX}/bin/rt

.include "../../mk/bsd.pkg.mk"
