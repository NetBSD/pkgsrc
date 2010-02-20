# $NetBSD: Makefile,v 1.1.1.1 2010/02/20 10:40:00 seb Exp $
#

DISTNAME=	Test-DNS-0.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-DNS/
COMMENT=	Perl 5 module to test DNS queries and zone configuration
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/DNS/.packlist

DEPENDS+=	p5-Moose>=0.8:../../devel/p5-Moose
DEPENDS+=	p5-Net-DNS>=0.65:../../net/p5-Net-DNS
DEPENDS+=	p5-Set-Object>=0:../../devel/p5-Set-Object
DEPENDS+=	p5-Test-Deep>=0:../../devel/p5-Test-Deep

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
