# $NetBSD: Makefile,v 1.2 2004/12/20 11:31:05 grant Exp $
#

DISTNAME=		I18N-LangTags-0.30
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ilt
PKGREVISION=		1
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=I18N/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Perl5 functions for dealing with RFC3066-style language tags

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/I18N/LangTags/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
