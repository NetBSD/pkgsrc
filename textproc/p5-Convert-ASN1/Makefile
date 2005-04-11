# $NetBSD: Makefile,v 1.16 2005/04/11 21:47:37 tv Exp $
#

DISTNAME=		Convert-ASN1-0.18
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5asn
PKGREVISION=		1
CATEGORIES=		converters perl5 textproc
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Convert-ASN1/
COMMENT=		Perl5 module to encode/decode ASN.1 data

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Convert/ASN1/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
