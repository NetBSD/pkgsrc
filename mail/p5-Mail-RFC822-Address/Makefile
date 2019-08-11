# $NetBSD: Makefile,v 1.15 2019/08/11 13:21:37 wiz Exp $
#

DISTNAME=	Mail-RFC822-Address-0.3
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Mail-RFC822-Address
COMMENT=	Perl extension for validating email addresses according to RFC822
LICENSE=	mit

PERL5_PACKLIST=	auto/Mail/RFC822/Address/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
