# $NetBSD: Makefile,v 1.7 2011/08/14 12:26:33 obache Exp $

DISTNAME=		Return-Value-1.666001
PKGNAME=		p5-${DISTNAME:S/666001/666.001/}
PKGREVISION=		2
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
