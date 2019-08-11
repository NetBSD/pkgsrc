# $NetBSD: Makefile,v 1.15 2019/08/11 13:22:20 wiz Exp $
#

DISTNAME=	Net-Google-Code-0.19
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	net devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Net-Google-Code
COMMENT=	Perl 5 simple client library for google code
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Net/Google/Code/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

BUILD_DEPENDS+=	p5-File-Slurp-[0-9]*:../../devel/p5-File-Slurp
BUILD_DEPENDS+=	p5-Test-Mock-LWP-[0-9]*:../../devel/p5-Test-Mock-LWP
BUILD_DEPENDS+=	p5-Test-MockModule-[0-9]*:../../devel/p5-Test-MockModule
DEPENDS+=	p5-Any-Moose-[0-9]*:../../devel/p5-Any-Moose
DEPENDS+=	p5-DateTime-[0-9]*:../../time/p5-DateTime
DEPENDS+=	p5-File-MMagic-[0-9]*:../../misc/p5-File-MMagic
DEPENDS+=	p5-HTML-Tree-[0-9]*:../../www/p5-HTML-Tree
DEPENDS+=	p5-JSON-[0-9]*:../../converters/p5-JSON
DEPENDS+=	p5-MIME-Types-[0-9]*:../../mail/p5-MIME-Types
DEPENDS+=	p5-Params-Validate-[0-9]*:../../devel/p5-Params-Validate
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-WWW-Mechanize-[0-9]*:../../www/p5-WWW-Mechanize
DEPENDS+=	p5-XML-FeedPP-[0-9]*:../../textproc/p5-XML-FeedPP

# for make test
BUILD_DEPENDS+=	p5-SUPER-[0-9]*:../../devel/p5-SUPER

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
