# $NetBSD: Makefile,v 1.8 2023/12/03 07:23:56 wen Exp $

DISTNAME=	Mail-Box-POP3-3.006
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Mail-Box-POP3/
COMMENT=	Handle POP3 folders as client
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Mail-Message>=3:../../mail/p5-Mail-Message
DEPENDS+=	p5-Mail-Box>=3:../../mail/p5-Mail-Box
DEPENDS+=	p5-Mail-Transport>=3:../../mail/p5-Mail-Transport

PERL5_PACKLIST=	auto/Mail/Box/POP3/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
