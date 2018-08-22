# $NetBSD: Makefile,v 1.42 2018/08/22 09:45:44 wiz Exp $
#

DISTNAME=		Business-CreditCard-0.36
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Business/}

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://theory.uwinnipeg.ca/CPAN/data/Business-CreditCard/CreditCard.html
#HOMEPAGE=		http://search.cpan.org/dist/Business-CreditCard/
COMMENT=		Perl5 module to validate/generate credit card checksums/names
LICENSE=		${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Business/CreditCard/.packlist

#pre-configure:
#	${CP} ${FILESDIR}/Makefile.PL ${WRKSRC}/Makefile.PL

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
