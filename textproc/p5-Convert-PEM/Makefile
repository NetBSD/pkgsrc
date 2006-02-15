# $NetBSD: Makefile,v 1.14 2006/02/15 00:50:33 heinz Exp $
#

DISTNAME=		Convert-PEM-0.07
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5pem
CATEGORIES=		converters perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Convert-PEM/
COMMENT=		Perl5 module to read/write ASN.1-encoded PEM files

DEPENDS+=		p5-MIME-Base64-[0-9]*:../../converters/p5-MIME-Base64
DEPENDS+=		p5-Convert-ASN1>=0.10:../../textproc/p5-Convert-ASN1
DEPENDS+=		p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5
DEPENDS+=		p5-Crypt-DES_EDE3-[0-9]*:../../security/p5-Crypt-DES_EDE3
DEPENDS+=		p5-Class-ErrorHandler-[0-9]*:../../devel/p5-Class-ErrorHandler

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Convert/PEM/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
