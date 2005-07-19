# $NetBSD: Makefile,v 1.10 2005/07/19 10:21:01 grant Exp $
#

DISTNAME=	Device-Gsm-1.36
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dgs
# PKGREVISION=	1
CATEGORIES=	comms perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Device/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl module to interface GSM cellular / modems

DEPENDS+=	p5-Device-Modem-[0-9]*:../../comms/p5-Device-Modem

PERL5_PACKLIST=		auto/Device/Gsm/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
