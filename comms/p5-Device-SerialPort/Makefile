# $NetBSD: Makefile,v 1.4 2001/11/25 18:01:58 jlam Exp $
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

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Device/SerialPort/.packlist

MAKE_PARAMS=	${DEFAULT_SERIAL_DEVICE}

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL ${MAKE_PARAMS}

.include "../../mk/bsd.pkg.mk"
