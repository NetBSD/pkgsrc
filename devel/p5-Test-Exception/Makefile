# $NetBSD: Makefile,v 1.9 2008/04/16 09:04:22 wiz Exp $
#

DISTNAME=		Test-Exception-0.27
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-Exception/
COMMENT=		Test exception based code

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-Sub-Uplevel>=0.18:../../devel/p5-Sub-Uplevel
DEPENDS+=		p5-Test-Simple>=0.7:../../devel/p5-Test-Simple

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/Exception/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
