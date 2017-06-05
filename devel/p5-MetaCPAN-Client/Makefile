# $NetBSD: Makefile,v 1.12 2017/06/05 14:23:13 ryoon Exp $

DISTNAME=	MetaCPAN-Client-2.011000
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/M/MI/MICKEY/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/MetaCPAN::Client
COMMENT=	Comprehensive, DWIM-featured client to the MetaCPAN API
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-JSON-MaybeXS-[0-9]*:../../converters/p5-JSON-MaybeXS
DEPENDS+=	p5-Safe-Isa-[0-9]*:../../devel/p5-Safe-Isa
DEPENDS+=	p5-Ref-Util-[0-9]*:../../devel/p5-Ref-Util

BUILD_DEPENDS+=	p5-ExtUtils-MakeMaker>=7.11.01:../../devel/p5-ExtUtils-MakeMaker
BUILD_DEPENDS+=	p5-Log-Any-[0-9]*:../../devel/p5-Log-Any
BUILD_DEPENDS+=	p5-Moo-[0-9]*:../../devel/p5-Moo
BUILD_DEPENDS+=	p5-Search-Elasticsearch-[0-9]*:../../devel/p5-Search-Elasticsearch
BUILD_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
BUILD_DEPENDS+=	p5-Any-URI-Escape-[0-9]*:../../www/p5-Any-URI-Escape
BUILD_DEPENDS+=	p5-WWW-Mechanize-Cached-[0-9]*:../../www/p5-WWW-Mechanize-Cached
BUILD_DEPENDS+=	p5-LWP-Protocol-https>=0:../../www/p5-LWP-Protocol-https

# for make test
BUILD_DEPENDS+=	p5-namespace-clean-[0-9]*:../../devel/p5-namespace-clean
BUILD_DEPENDS+=	p5-Ref-Util-[0-9]*:../../devel/p5-Ref-Util

PERL5_PACKLIST=		auto/MetaCPAN/Client/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
