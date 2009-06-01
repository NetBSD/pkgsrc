# $NetBSD: Makefile,v 1.2 2009/06/01 19:13:56 sno Exp $
#

DISTNAME=	Test-Reporter-1.54
PKGNAME=	p5-${DISTNAME}00
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-Base/
COMMENT=	Perl module which sends test results to cpan-testers@perl.org

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/Reporter/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
