# $NetBSD: Makefile,v 1.4 2016/06/08 19:24:21 wiz Exp $

DISTNAME=	Crypt-X509-0.51
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Crypt-X509/
COMMENT=	Perl 5 module to parse a X.509 certificate
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Convert-ASN1-[0-9]*:../../textproc/p5-Convert-ASN1

PERL5_PACKLIST=	auto/Crypt/X509/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
