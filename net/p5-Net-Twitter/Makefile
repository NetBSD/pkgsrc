# $NetBSD: Makefile,v 1.13 2011/08/14 14:14:47 obache Exp $
#

DISTNAME=	Net-Twitter-3.13008
PKGNAME=	p5-${DISTNAME}
#PKGREVISION=	1
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-Twitter/
COMMENT=	Perl interface to the Twitter API
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Data-Visitor-[0-9]*:../../devel/p5-Data-Visitor
DEPENDS+=	p5-DateTime>=0.5100:../../time/p5-DateTime
DEPENDS+=	p5-DateTime-Format-Strptime>=1.0900:../../time/p5-DateTime-Format-Strptime
DEPENDS+=	p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser
DEPENDS+=	p5-JSON-Any>=1.21:../../converters/p5-JSON-Any
DEPENDS+=	p5-JSON-XS-[0-9]*:../../converters/p5-JSON-XS
DEPENDS+=	p5-Moose>=0.90:../../devel/p5-Moose
#DEPENDS+=	p5-MooseX-AttributeHelpers-[0-9]*:../../devel/p5-MooseX-AttributeHelpers
DEPENDS+=	p5-MooseX-MultiInitArg-[0-9]*:../../devel/p5-MooseX-MultiInitArg
DEPENDS+=	p5-Net-[0-9]*:../../net/p5-Net
DEPENDS+=	p5-Net-OAuth>=0.20:../../net/p5-Net-OAuth
DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny
DEPENDS+=	p5-URI>=1.40:../../www/p5-URI
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-namespace-autoclean>=0.09:../../devel/p5-namespace-autoclean

BUILD_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.88}:../../devel/p5-Test-Simple

PERL5_PACKLIST=	auto/Net/Twitter/.packlist
USE_LANGUAGES=	# none
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
