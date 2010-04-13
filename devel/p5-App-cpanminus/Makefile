# $NetBSD: Makefile,v 1.1.1.1 2010/04/13 01:32:37 seb Exp $
#

DISTNAME=		App-cpanminus-0.9934
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=App/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/App-cpanminus/
COMMENT=		Perl5 script to get, unpack, build and install modules from CPAN
LICENSE=		${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/App/cpanminus/.packlist

DEPENDS+=		p5-Module-Build>=0.36000:../../devel/p5-Module-Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
