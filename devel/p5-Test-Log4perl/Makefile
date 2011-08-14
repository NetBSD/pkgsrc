# $NetBSD: Makefile,v 1.5 2011/08/14 12:26:41 obache Exp $
#

DISTNAME=	Test-Log4perl-0.1001
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-Log4perl/
COMMENT=	Perl 5 module to test Log::Log4perl

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/Log4perl/.packlist

DEPENDS+=	p5-Class-Accessor-Chained-[0-9]*:../../devel/p5-Class-Accessor-Chained
DEPENDS+=	p5-Lingua-EN-Numbers-Ordinate-[0-9]*:../../textproc/p5-Lingua-EN-Numbers-Ordinate
DEPENDS+=	p5-Log-Log4perl-[0-9]*:../../devel/p5-Log-Log4perl
DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
