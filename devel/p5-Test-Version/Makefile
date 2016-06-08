# $NetBSD: Makefile,v 1.7 2016/06/08 19:23:42 wiz Exp $
#

DISTNAME=		Test-Version-2.03
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-Version/
COMMENT=		Check to see that version's in modules are sane
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-File-Find-Rule-Perl>=0:../../devel/p5-File-Find-Rule-Perl
DEPENDS+=		p5-Module-Metadata>=0:../../devel/p5-Module-Metadata

BUILD_DEPENDS+=		p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/Version/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
