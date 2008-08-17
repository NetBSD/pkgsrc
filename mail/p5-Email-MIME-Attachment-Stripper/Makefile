# $NetBSD: Makefile,v 1.3 2008/08/17 18:19:42 he Exp $
#

DISTNAME=	Email-MIME-Attachment-Stripper-1.315
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Email-MIME-Attachment-Stripper/
COMMENT=	Strip the attachments from a mail

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Email-MIME>=1.861:../../mail/p5-Email-MIME
DEPENDS+=	p5-Email-MIME-ContentType>=1.0:../../mail/p5-Email-MIME-ContentType
DEPENDS+=	p5-Email-MIME-Modifier>=1.442:../../mail/p5-Email-MIME-Modifier

PERL5_PACKLIST=	auto/Email/MIME/Attachment/Stripper/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
