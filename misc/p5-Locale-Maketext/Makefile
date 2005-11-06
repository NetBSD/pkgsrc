# $NetBSD: Makefile,v 1.7 2005/11/06 22:15:02 kristerw Exp $
#

DISTNAME=		Locale-Maketext-1.09
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5lmt
PKGREVISION=		1
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Locale/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Locale-Maketext/
COMMENT=		Perl framework for localization

DEPENDS+=		p5-I18N-LangTags>=0.30:../../misc/p5-I18N-LangTags

PERL5_PACKLIST=		auto/Locale-Maketext/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
