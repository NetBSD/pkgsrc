# $NetBSD: Makefile,v 1.9 2011/08/14 13:25:23 obache Exp $
#

DISTNAME=	Email-MIME-Attachment-Stripper-1.316
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Email-MIME-Attachment-Stripper/
COMMENT=	Strip the attachments from a mail

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Email-MIME>=1.903:../../mail/p5-Email-MIME
DEPENDS+=	p5-Email-MIME-ContentType>=1.0:../../mail/p5-Email-MIME-ContentType

PERL5_PACKLIST=	auto/Email/MIME/Attachment/Stripper/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
