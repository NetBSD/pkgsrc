# $NetBSD: Makefile,v 1.2 2001/02/16 13:56:19 wiz Exp $
#

DISTNAME=	Device-SerialPort-0.070
PKGNAME=	p5-${DISTNAME}
WRKSRC=		${WRKDIR}/Device-SerialPort-0.07
CATEGORIES=	comms perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Device/}

MAINTAINER=	damon@brodiefamily.org
HOMEPAGE=	http://members.aol.com/Bbirthisel/alpha.html
COMMENT=	POSIX-based Perl module to control your serial port

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Device/SerialPort/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
