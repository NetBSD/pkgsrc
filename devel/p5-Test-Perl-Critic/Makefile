# $NetBSD: Makefile,v 1.2 2008/06/12 02:14:27 joerg Exp $
#

DISTNAME=	Test-Perl-Critic-1.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-Perl-Critic/
COMMENT=	Perl 5 module providing a Perl::Critic interface for test programs

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Perl-Critic>=0.21:../../devel/p5-Perl-Critic

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/Perl/Critic/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
