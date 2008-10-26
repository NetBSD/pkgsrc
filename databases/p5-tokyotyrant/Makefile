# $NetBSD: Makefile,v 1.1.1.1 2008/10/26 11:40:33 obache Exp $
#

DISTNAME=	tokyotyrant-perl-1.2
PKGNAME=	p5-${DISTNAME:S/-perl-/-/}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tokyocabinet/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://tokyocabinet.sourceforge.net/tyrantperldoc/
COMMENT=	Pure Perl Interface of Tokyo Tyrant

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/TokyoTyrant/.packlist
USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	share/tokyotyrant/doc/perl

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/index.html \
		${DESTDIR}${PREFIX}/share/tokyotyrant/doc/perl/index.html

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
