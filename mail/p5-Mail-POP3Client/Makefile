# $NetBSD: Makefile,v 1.11 2020/08/31 18:10:04 wiz Exp $
#

DISTNAME=	Mail-POP3Client-2.19
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
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
