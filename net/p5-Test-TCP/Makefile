# $NetBSD: Makefile,v 1.30 2019/11/08 15:10:19 mef Exp $

DISTNAME=	Test-TCP-2.22
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-TCP
COMMENT=	Perl 5 module to test TCP program
LICENSE=	${PERL5_LICENSE}

TEST_DEPENDS+=		p5-Test-SharedFork>=0.19:../../devel/p5-Test-SharedFork

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/TCP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
