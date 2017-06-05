# $NetBSD: Makefile,v 1.31 2017/06/05 14:24:38 ryoon Exp $
#

DISTNAME=		Convert-PEM-0.08
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		7
CATEGORIES=		converters perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Convert-PEM/
COMMENT=		Perl5 module to read/write ASN.1-encoded PEM files
LICENSE=		${PERL5_LICENSE}

#DEPENDS+=		{perl>=5.7.3,p5-MIME-Base64-[0-9]*}:../../converters/p5-MIME-Base64
DEPENDS+=		p5-Convert-ASN1>=0.10:../../textproc/p5-Convert-ASN1
#DEPENDS+=		{perl>=5.7.3,p5-Digest-MD5-[0-9]*}:../../security/p5-Digest-MD5
DEPENDS+=		p5-Crypt-DES_EDE3-[0-9]*:../../security/p5-Crypt-DES_EDE3
DEPENDS+=		p5-Class-ErrorHandler-[0-9]*:../../devel/p5-Class-ErrorHandler

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Convert/PEM/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
