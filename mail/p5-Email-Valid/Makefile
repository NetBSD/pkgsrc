# $NetBSD: Makefile,v 1.2 2001/09/27 07:36:12 jlam Exp $

DISTNAME=		Email-Valid-0.13
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		mail perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=		packages@netbsd.org
COMMENT=		perl5 module for testing validity of an email address

DEPENDS+=		p5-MailTools-[0-9]*:../../mail/p5-MailTools
DEPENDS+=		p5-Net-DNS-[0-9]*:../../net/p5-Net-DNS

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Email/Valid/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
