# $NetBSD: Makefile,v 1.1.1.1 2003/02/12 00:51:48 mjl Exp $
#

DISTNAME=	Device-Modem-1.24
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dmd
CATEGORIES=	comms perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Device/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Perl module to talk to modem devices connected via serial port

DEPENDS+=	p5-Device-SerialPort-[0-9]*:../p5-Device-SerialPort

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Device/Modem/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
