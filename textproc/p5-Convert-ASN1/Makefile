# $NetBSD: Makefile,v 1.21 2007/05/17 21:09:40 seb Exp $
#

DISTNAME=		Convert-ASN1-0.21
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5asn
CATEGORIES=		converters perl5 textproc
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Convert-ASN1/
COMMENT=		Perl5 module to encode/decode ASN.1 data

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Convert/ASN1/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
