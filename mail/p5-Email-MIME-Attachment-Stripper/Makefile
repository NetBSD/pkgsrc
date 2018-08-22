# $NetBSD: Makefile,v 1.18 2018/08/22 09:45:28 wiz Exp $
#

DISTNAME=	Email-MIME-Attachment-Stripper-1.317
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Email-MIME-Attachment-Stripper/
COMMENT=	Strip the attachments from a mail
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Email-MIME>=1.903:../../mail/p5-Email-MIME
DEPENDS+=	p5-Email-MIME-ContentType>=1.016:../../mail/p5-Email-MIME-ContentType

PERL5_PACKLIST=	auto/Email/MIME/Attachment/Stripper/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
