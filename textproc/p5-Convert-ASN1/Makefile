# $NetBSD: Makefile,v 1.18 2005/08/06 06:19:31 jlam Exp $
#

DISTNAME=		Convert-ASN1-0.18
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5asn
PKGREVISION=		2
CATEGORIES=		converters perl5 textproc
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Convert-ASN1/
COMMENT=		Perl5 module to encode/decode ASN.1 data

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Convert/ASN1/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
