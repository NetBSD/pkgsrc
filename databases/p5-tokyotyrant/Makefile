# $NetBSD: Makefile,v 1.21 2011/08/14 08:18:12 obache Exp $
#

DISTNAME=	tokyotyrant-perl-1.16
PKGNAME=	p5-${DISTNAME:S/-perl-/-/}
PKGREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	${HOMEPAGE:S/perldoc/perlpkg/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://fallabs.com/tokyotyrant/perldoc/
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
