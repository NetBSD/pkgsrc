# $NetBSD: Makefile,v 1.9 2010/08/03 04:27:08 seb Exp $
#

DISTNAME=		App-cpanminus-1.0010
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
