# $NetBSD: Makefile,v 1.3 2005/03/02 22:30:31 wiz Exp $
#

DISTNAME=		Locale-Maketext-1.09
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5lmt
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Locale/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Locale-Maketext/
COMMENT=		Perl framework for localization

DEPENDS+=		p5-I18N-LangTags>=0.30:../p5-I18N-LangTags

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Locale-Maketext/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
