# $NetBSD: Makefile,v 1.8 2005/05/18 13:35:11 mjl Exp $
#

DISTNAME=	Device-Gsm-1.36
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dgs
# PKGREVISION=	1
CATEGORIES=	comms perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Device/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl module to interface GSM cellular / modems

DEPENDS+=	p5-Device-Modem-[0-9]*:../p5-Device-Modem

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Device/Gsm/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
