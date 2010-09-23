# $NetBSD: Makefile,v 1.13 2010/09/23 21:19:08 sno Exp $
#

DISTNAME=		App-cpanminus-1.0014
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

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
