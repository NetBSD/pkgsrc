# $NetBSD: Makefile,v 1.2 2015/02/14 12:03:54 mef Exp $
#

DISTNAME=	MooseX-App-1.31
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~maros/MooseX-App/lib/MooseX/App.pm
COMMENT=	Write user-friendly command line apps with even less suffering
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Test-Most-[0-9]*:../../devel/p5-Test-Most

PERL5_PACKLIST=	auto/MooseX/App/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
