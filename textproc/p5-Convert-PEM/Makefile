# $NetBSD: Makefile,v 1.8 2003/07/21 17:27:36 martti Exp $
#

DISTNAME=		Convert-PEM-0.06
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5pem
CATEGORIES=		converters perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=		tech-pkg@NetBSD.org
#HOMEPAGE=	
COMMENT=		Perl5 module to read/write ASN.1-encoded PEM files

DEPENDS+=		p5-MIME-Base64-[0-9]*:../../converters/p5-MIME-Base64
DEPENDS+=		p5-Convert-ASN1-[0-9]*:../../textproc/p5-Convert-ASN1
DEPENDS+=		p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5
DEPENDS+=		p5-Crypt-DES-[0-9]*:../../security/p5-Crypt-DES
DEPENDS+=		p5-Crypt-DES_EDE3-[0-9]*:../../security/p5-Crypt-DES_EDE3

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Convert/PEM/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
