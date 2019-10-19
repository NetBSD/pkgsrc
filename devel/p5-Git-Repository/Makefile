# $NetBSD: Makefile,v 1.27 2019/10/19 13:11:41 mef Exp $

DISTNAME=	Git-Repository-1.324
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Git/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Git-Repository
COMMENT=	Perl interface to Git repositories
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	git-base-[0-9]*:../../devel/git-base
DEPENDS+=	p5-System-Command>=1.103:../../devel/p5-System-Command
DEPENDS+=	p5-Git-Version-Compare>=1.001:../../devel/p5-Git-Version-Compare

TEST_DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean
TEST_DEPENDS+=	p5-Test-Requires-Git-[0-9]*:../../devel/p5-Test-Requires-Git

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Git/Repository/.packlist

USE_TOOLS+=	perl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
