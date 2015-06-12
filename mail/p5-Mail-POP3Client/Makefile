# $NetBSD: Makefile,v 1.4 2015/06/12 10:50:24 wiz Exp $
#

DISTNAME=	Mail-POP3Client-2.18
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Mail-POP3Client/
COMMENT=	Perl 5 module to talk to a POP3 (RFC1939) server

PERL5_PACKLIST=	auto/Mail/POP3Client/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
