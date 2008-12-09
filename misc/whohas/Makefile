# $NetBSD: Makefile,v 1.1.1.1 2008/12/09 10:53:10 wiz Exp $
#

DISTNAME=	whohas-0.21
CATEGORIES=	misc
MASTER_SITES=	http://www.philippwesche.org/200811/whohas/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.philippwesche.org/200811/whohas/intro.html
COMMENT=	Query several packaging systems for a program

DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	wget-[0-9]*:../../net/wget

USE_LANGUAGES=	# none

REPLACE_PERL=	whohas

INSTALLATION_DIRS=	bin share/doc/whohas

do-build:
	# nothing

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/whohas ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/intro* ${DESTDIR}${PREFIX}/share/doc/whohas

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
