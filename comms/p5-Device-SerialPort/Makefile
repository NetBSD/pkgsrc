# $NetBSD: Makefile,v 1.8.2.1 2003/03/07 07:50:04 jmc Exp $
#

DISTNAME=	Device-SerialPort-0.12
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dse
CATEGORIES=	comms perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Device/}

MAINTAINER=	damon@brodiefamily.org
HOMEPAGE=	http://members.aol.com/Bbirthisel/alpha.html
COMMENT=	POSIX-based Perl module to control your serial port

DEPENDS+=	p5-perl-headers-[0-9]*:../../devel/p5-perl-headers

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Device/SerialPort/.packlist

MAKE_PARAMS=	${DEFAULT_SERIAL_DEVICE}

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
