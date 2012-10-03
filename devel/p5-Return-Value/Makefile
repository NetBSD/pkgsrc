# $NetBSD: Makefile,v 1.8 2012/10/03 21:55:32 wiz Exp $

DISTNAME=		Return-Value-1.666001
PKGNAME=		p5-${DISTNAME:S/666001/666.001/}
PKGREVISION=		3
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../by-authors/id/R/RJ/RJBS/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Return-Value/
COMMENT=		Polymorphic Return Values
LICENSE=		${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		{perl>=5.7.3,p5-Test-Simple>=0.47}:../../devel/p5-Test-Simple

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Return/Value/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
