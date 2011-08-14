# $NetBSD: Makefile,v 1.4 2011/08/14 14:14:49 obache Exp $
#

DISTNAME=	Test-DNS-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-DNS/
COMMENT=	Perl 5 module to test DNS queries and zone configuration
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir
PERL5_MODULE_TYPE=	Module::Build

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/DNS/.packlist

BUILD_DEPENDS+=	{perl>=5.11.4,p5-Module-Build>=0.3601}:../../devel/p5-Module-Build
BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
DEPENDS+=	p5-Moose>=0.8:../../devel/p5-Moose
DEPENDS+=	p5-Net-DNS>=0:../../net/p5-Net-DNS
DEPENDS+=	p5-Set-Object>=0:../../devel/p5-Set-Object
DEPENDS+=	p5-Test-Deep>=0:../../devel/p5-Test-Deep

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
