# $NetBSD: Makefile,v 1.9 2012/10/08 12:19:21 asau Exp $
#

DISTNAME=	Email-Reply-1.202
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	mail
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/R/RJ/RJBS/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/R/RJ/RJBS/
COMMENT=	Reply to a Message

DEPENDS+=	p5-Email-Abstract>=2.01:../../mail/p5-Email-Abstract
DEPENDS+=	p5-Email-Address>=1.80:../../mail/p5-Email-Address
DEPENDS+=	p5-Email-MIME>=1.903:../../mail/p5-Email-MIME

PERL5_PACKLIST=	auto/Email/Reply/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
