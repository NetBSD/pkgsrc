# $NetBSD: Makefile,v 1.11 2004/05/02 04:19:41 snj Exp $

DISTNAME=	Mail-Audit-2.0
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5mau
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 module for filtering mail

DEPENDS+=	p5-MailTools-[0-9]*:../../mail/p5-MailTools
DEPENDS+=	p5-Mail-ListDetector-[0-9]*:../../mail/p5-Mail-ListDetector
# We need Net::SMTP from p5-Net.
DEPENDS+=	p5-Net>=1.0:../../net/p5-Net

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Mail/Audit/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
