# $NetBSD: Makefile,v 1.6 2002/10/20 17:46:00 seb Exp $
#

DISTNAME=	Device-SerialPort-0.070
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dse
WRKSRC=		${WRKDIR}/Device-SerialPort-0.07
CATEGORIES=	comms perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Device/}

MAINTAINER=	damon@brodiefamily.org
HOMEPAGE=	http://members.aol.com/Bbirthisel/alpha.html
COMMENT=	POSIX-based Perl module to control your serial port

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Device/SerialPort/.packlist

MAKE_PARAMS=	${DEFAULT_SERIAL_DEVICE}

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
