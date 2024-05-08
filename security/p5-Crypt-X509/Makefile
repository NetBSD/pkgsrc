# $NetBSD: Makefile,v 1.16 2024/05/08 11:43:27 wiz Exp $

DISTNAME=	Crypt-X509-0.55
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Crypt-X509
COMMENT=	Perl 5 module to parse a X.509 certificate
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Convert-ASN1-[0-9]*:../../textproc/p5-Convert-ASN1

PERL5_PACKLIST=	auto/Crypt/X509/.packlist

Cannot restore extended attributes: com.apple.*
USE_TOOLS+=					bsdtar
EXTRACT_OPTS_TAR.Crypt-X509-0.55.tar.gz=	--no-xattr

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
