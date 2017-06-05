# $NetBSD: Makefile,v 1.16 2017/06/05 14:24:04 ryoon Exp $
#

DISTNAME=	Email-Reply-1.204
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/R/RJ/RJBS/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/R/RJ/RJBS/
COMMENT=	Reply to a Message
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Email-Abstract>=2.01:../../mail/p5-Email-Abstract
DEPENDS+=	p5-Email-Address>=1.80:../../mail/p5-Email-Address
DEPENDS+=	p5-Email-MIME>=1.903:../../mail/p5-Email-MIME

PERL5_PACKLIST=	auto/Email/Reply/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
