# $NetBSD: Makefile,v 1.1.1.1 2004/05/13 08:21:08 mjl Exp $
#

DISTNAME=		I18N-LangTags-0.30
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ilt
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=I18N/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Perl5 functions for dealing with RFC3066-style language tags

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/I18N/LangTags/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
