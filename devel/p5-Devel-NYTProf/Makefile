# $NetBSD: Makefile,v 1.2 2009/02/15 23:16:10 seb Exp $
#

DISTNAME=	Devel-NYTProf-2.08
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-NYTProf/
COMMENT=	Powerful feature-rich Perl 5 source code profiler

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Devel/NYTProf/.packlist

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
