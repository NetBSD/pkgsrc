# $NetBSD: Makefile,v 1.11 2003/06/02 01:16:36 jschauma Exp $
#

DISTNAME=		Convert-ASN1-0.16
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5asn
CATEGORIES=		converters perl5 textproc
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=		tech-pkg@netbsd.org
#HOMEPAGE=	
COMMENT=		perl5 module to encode/decode ASN.1 data

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Convert/ASN1/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
