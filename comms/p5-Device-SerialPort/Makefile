# $NetBSD: Makefile,v 1.9 2003/02/13 19:29:33 mjl Exp $
#

DISTNAME=	Device-SerialPort-0.12
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dse
CATEGORIES=	comms perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Device/}

MAINTAINER=	damon@brodiefamily.org
HOMEPAGE=	http://members.aol.com/Bbirthisel/alpha.html
COMMENT=	POSIX-based Perl module to control your serial port

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Device/SerialPort/.packlist

MAKE_PARAMS=	${DEFAULT_SERIAL_DEVICE}

pre-configure:
	cd /usr/include; h2ph -d ${WRKSRC} -a sys/termios.h

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
