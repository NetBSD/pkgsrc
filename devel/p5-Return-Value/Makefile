# $NetBSD: Makefile,v 1.2 2008/06/12 02:14:25 joerg Exp $

DISTNAME=		Return-Value-1.302
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../by-authors/id/R/RJ/RJBS/}

MAINTAINER=		kuli0020@umn.edu
HOMEPAGE=		http://search.cpan.org/dist/Return-Value/
COMMENT=		Polymorphic Return Values

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		{perl>=5.7.3,p5-Test-Simple>=0.47}:../../devel/p5-Test-Simple

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Return/Value/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
