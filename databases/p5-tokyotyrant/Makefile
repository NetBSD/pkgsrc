# $NetBSD: Makefile,v 1.15 2009/07/07 11:43:01 obache Exp $
#

DISTNAME=	tokyotyrant-perl-1.13
PKGNAME=	p5-${DISTNAME:S/-perl-/-/}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tokyocabinet/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://tokyocabinet.sourceforge.net/tyrantperldoc/
COMMENT=	Pure Perl Interface of Tokyo Tyrant
LICENSES=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/TokyoTyrant/.packlist
USE_LANGUAGES=	# none

REPLACE_PERL=	*.pl

INSTALLATION_DIRS+=	share/tokyotyrant/doc/perl

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/index.html \
		${DESTDIR}${PREFIX}/share/tokyotyrant/doc/perl/index.html

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
