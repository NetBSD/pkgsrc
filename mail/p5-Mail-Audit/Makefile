# $NetBSD: Makefile,v 1.17 2006/02/02 12:08:14 salo Exp $

DISTNAME=	Mail-Audit-2.1
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5mau
PKGREVISION=	2
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Mail-Audit/
COMMENT=	Perl5 module for filtering mail

DEPENDS+=	p5-MailTools-[0-9]*:../../mail/p5-MailTools
DEPENDS+=	p5-Mail-ListDetector-[0-9]*:../../mail/p5-Mail-ListDetector
DEPENDS+=	p5-MIME-tools-[0-9]*:../../mail/p5-MIME-tools
# We need Net::SMTP from p5-Net.
DEPENDS+=	p5-Net>=1.0:../../net/p5-Net

PERL5_PACKLIST=		auto/Mail/Audit/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
