# $NetBSD: Makefile,v 1.3 2019/07/02 07:27:06 wen Exp $

DISTNAME=	Mail-Box-IMAP4-3.007
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Mail-Box-IMAP4/
COMMENT=	Handle IMAP4 folders as client
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Digest-HMAC-[0-9]*:../../security/p5-Digest-HMAC
DEPENDS+=	p5-Mail-Message>=3.008:../../mail/p5-Mail-Message
DEPENDS+=	p5-Mail-Box>=3:../../mail/p5-Mail-Box
DEPENDS+=	p5-Mail-Transport>=3:../../mail/p5-Mail-Transport
DEPENDS+=	p5-Mail-IMAPClient>=0:../../mail/p5-Mail-IMAPClient

PERL5_PACKLIST=	auto/Mail/Box/IMAP4/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
