# $NetBSD: Makefile,v 1.7 2011/08/16 09:36:55 obache Exp $
#

DISTNAME=	Test-Perl-Critic-1.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-Perl-Critic/
COMMENT=	Perl 5 module providing a Perl::Critic interface for test programs
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Perl-Critic>=1.105:../../devel/p5-Perl-Critic

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/Perl/Critic/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
