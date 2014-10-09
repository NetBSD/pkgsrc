# $NetBSD: Makefile,v 1.33 2014/10/09 14:07:02 wiz Exp $
#

DISTNAME=		Convert-ASN1-0.26
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		converters perl5 textproc
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Convert-ASN1/
COMMENT=		Perl5 module to encode/decode ASN.1 data
LICENSE=		${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Convert/ASN1/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
