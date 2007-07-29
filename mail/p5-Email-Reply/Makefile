# $NetBSD: Makefile,v 1.1.1.1 2007/07/29 12:10:38 adrianp Exp $
#

DISTNAME=	Email-Reply-1.202
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/R/RJ/RJBS/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/R/RJ/RJBS/
COMMENT=	Reply to a Message

DEPENDS+=	p5-Email-Abstract>=2.01:../../mail/p5-Email-Abstract
DEPENDS+=	p5-Email-Address>=1.80:../../mail/p5-Email-Address
DEPENDS+=	p5-Email-MIME>=1.82:../../mail/p5-Email-MIME
DEPENDS+=	p5-Email-MIME-Creator>=1.41:../../mail/p5-Email-MIME-Creator
DEPENDS+=	p5-Email-MIME-Modifier>=1.42:../../mail/p5-Email-MIME-Modifier

PERL5_PACKLIST=	auto/Email/Reply/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
