# $NetBSD: Makefile,v 1.30 2013/05/31 12:42:08 wiz Exp $
#

DISTNAME=		Convert-ASN1-0.26
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
SVR4_PKGNAME=		p5asn
CATEGORIES=		converters perl5 textproc
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Convert-ASN1/
COMMENT=		Perl5 module to encode/decode ASN.1 data
LICENSE=		${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Convert/ASN1/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
