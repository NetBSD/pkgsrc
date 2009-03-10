# $NetBSD: Makefile,v 1.1.1.1 2009/03/10 21:22:59 seb Exp $
#

DISTNAME=	Perl-Version-1.009
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Perl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Perl-Version/
COMMENT=	Perl 5 module to parse and manipulate Perl version strings

USE_LANGUAGES=		# empty
MAKE_ENV+=		PERL_MM_USE_DEFAULT=1
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-File-Slurp>=9999.12:../../devel/p5-File-Slurp

PERL5_PACKLIST=		auto/Perl/Version/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
