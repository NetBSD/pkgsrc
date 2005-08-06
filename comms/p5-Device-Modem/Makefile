# $NetBSD: Makefile,v 1.10 2005/08/06 06:19:05 jlam Exp $
#

DISTNAME=	Device-Modem-1.36
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dmd
PKGREVISION=	2
CATEGORIES=	comms perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Device/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl module to talk to modem devices connected via serial port

DEPENDS+=	p5-Device-SerialPort-[0-9]*:../../comms/p5-Device-SerialPort

PERL5_PACKLIST=		auto/Device/Modem/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
