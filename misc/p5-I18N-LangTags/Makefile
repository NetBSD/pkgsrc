# $NetBSD: Makefile,v 1.14 2013/04/07 02:36:22 markd Exp $
#

DISTNAME=		I18N-LangTags-0.35
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		6
SVR4_PKGNAME=		p5ilt
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=I18N/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/I18N-LangTags/
COMMENT=		Perl5 functions for dealing with RFC3066-style language tags

PERL5_PACKLIST=		auto/I18N/LangTags/.packlist

post-patch:
	rm ${WRKSRC}/lib/I18N/LangTags/Detect.pm.orig

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
