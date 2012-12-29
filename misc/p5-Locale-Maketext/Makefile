# $NetBSD: Makefile,v 1.19 2012/12/29 01:41:27 obache Exp $
#

DISTNAME=		Locale-Maketext-1.23
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5lmt
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Locale/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Locale-Maketext/
COMMENT=		Perl framework for localization
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		{perl>=5.8.5,p5-I18N-LangTags>=0.31}:../../misc/p5-I18N-LangTags

PERL5_PACKLIST=		auto/Locale-Maketext/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
