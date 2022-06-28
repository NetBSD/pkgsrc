# $NetBSD: Makefile,v 1.14 2022/06/28 11:34:29 wiz Exp $
#

DISTNAME=	Mail-POP3Client-2.21
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Mail-POP3Client
COMMENT=	Perl 5 module to talk to a POP3 (RFC1939) server
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Mail/POP3Client/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
