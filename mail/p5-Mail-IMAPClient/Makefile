# $NetBSD: Makefile,v 1.13 2005/04/11 21:46:21 tv Exp $
#

DISTNAME=       Mail-IMAPClient-2.2.9
PKGNAME=        p5-${DISTNAME}
SVR4_PKGNAME=	p5mic
PKGREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 module for talking to RFC-2060 IMAP servers

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Mail/IMAPClient/.packlist

pre-configure:
	@cd ${WRKSRC} && ${TOUCH} ${TOUCH_FLAGS} test.txt

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
