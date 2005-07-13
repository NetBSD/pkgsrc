# $NetBSD: Makefile,v 1.20 2005/07/13 18:01:33 jlam Exp $
#

DISTNAME=		Business-CreditCard-0.27
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5buc
PKGREVISION=		1
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Business/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://theory.uwinnipeg.ca/CPAN/data/Business-CreditCard/CreditCard.html
COMMENT=		Perl5 module to validate/generate credit card checksums/names

PERL5_PACKLIST=		auto/Business/CreditCard/.packlist

pre-configure:
	${CP} ${FILESDIR}/Makefile.PL ${WRKSRC}/Makefile.PL

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
