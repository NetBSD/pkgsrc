# $NetBSD: Makefile,v 1.12 2004/12/20 11:30:56 grant Exp $
#

DISTNAME=	Device-SerialPort-0.12
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dse
PKGREVISION=	1
CATEGORIES=	comms perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Device/}

MAINTAINER=	damon@brodiefamily.org
HOMEPAGE=	http://members.aol.com/Bbirthisel/alpha.html
COMMENT=	POSIX-based Perl module to control your serial port

DEPENDS+=	p5-perl-headers-[0-9]*:../../devel/p5-perl-headers

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Device/SerialPort/.packlist

MAKE_PARAMS=	${DEFAULT_SERIAL_DEVICE}

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
