# $NetBSD: Makefile,v 1.2 2026/07/16 19:01:52 wiz Exp $

DISTNAME=	App-find2perl-1.005
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=App/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/App::find2perl
COMMENT=	Translate find command lines to Perl code
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/App/find2perl/.packlist
USE_LANGUAGES=	# none

TEST_DEPENDS+=	p5-Devel-FindPerl-[0-9]*:../../devel/p5-Devel-FindPerl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
