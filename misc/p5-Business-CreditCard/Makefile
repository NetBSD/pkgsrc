# $NetBSD: Makefile,v 1.17 2004/04/27 02:24:08 snj Exp $
#

DISTNAME=		Business-CreditCard-0.27
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5buc
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Business/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://theory.uwinnipeg.ca/CPAN/data/Business-CreditCard/CreditCard.html
COMMENT=		Perl5 module to validate/generate credit card checksums/names

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Business/CreditCard/.packlist

pre-configure:
	${CP} ${FILESDIR}/Makefile.PL ${WRKSRC}/Makefile.PL

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
