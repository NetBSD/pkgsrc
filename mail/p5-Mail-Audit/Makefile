# $NetBSD: Makefile,v 1.1.1.1 2001/09/27 05:08:37 jlam Exp $

DISTNAME=		Mail-Audit-1.11
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		mail perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=		packages@netbsd.org
COMMENT=		perl5 module for filtering mail

DEPENDS+=		p5-MailTools-*:../../mail/p5-MailTools
DEPENDS+=		p5-Mail-ListDetector-*:../../mail/p5-Mail-ListDetector
# We need Net::SMTP from p5-Net.
DEPENDS+=		p5-Net>=1.0:../../net/p5-Net

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Mail/Audit/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
