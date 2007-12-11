# $NetBSD: Makefile,v 1.3 2007/12/11 11:58:04 rhaen Exp $

DISTNAME=		Test-NoWarnings-0.084
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		rhaen@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-NoWarnings/
COMMENT=		Perl5 module to make sure you didn't emit any warnings while testing

DEPENDS+=		p5-Test-Tester>=0.103:../../devel/p5-Test-Tester

PKG_DESTDIR_SUPPORT=	user-destdir
PERL5_PACKLIST=		auto/Test/NoWarnings/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
