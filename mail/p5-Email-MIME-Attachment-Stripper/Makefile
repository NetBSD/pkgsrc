# $NetBSD: Makefile,v 1.1.1.1 2007/07/29 12:12:55 adrianp Exp $
#

DISTNAME=	Email-MIME-Attachment-Stripper-1.313
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/R/RJ/RJBS/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/R/RJ/RJBS/
COMMENT=	Strip the attachments from a mail

DEPENDS+=	p5-Email-MIME>=1.82:../../mail/p5-Email-MIME
DEPENDS+=	p5-Email-MIME-ContentType>=1.0:../../mail/p5-Email-MIME-ContentType
DEPENDS+=	p5-Email-MIME-Modifier>=1.41:../../mail/p5-Email-MIME-Modifier

PERL5_PACKLIST=	auto/Email/MIME/Attachment/Stripper/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
