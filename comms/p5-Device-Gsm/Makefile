# $NetBSD: Makefile,v 1.2 2003/06/02 01:21:21 jschauma Exp $
#

DISTNAME=	Device-Gsm-1.16
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dgs
CATEGORIES=	comms perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Device/}

MAINTAINER=	tech-pkg@netbsd.org
COMMENT=	Perl module to interface GSM cellular / modems

DEPENDS+=	p5-Device-Modem-[0-9]*:../p5-Device-Modem

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Device/Gsm/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
