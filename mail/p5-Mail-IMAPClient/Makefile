# $NetBSD: Makefile,v 1.10 2004/01/31 14:47:13 toshii Exp $
#

DISTNAME=       Mail-IMAPClient-2.2.9
PKGNAME=        p5-${DISTNAME}
SVR4_PKGNAME=	p5mic
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 module for talking to RFC-2060 IMAP servers

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Mail/IMAPClient/.packlist

pre-configure:
	@cd ${WRKSRC} && ${TOUCH} ${TOUCH_FLAGS} test.txt

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
