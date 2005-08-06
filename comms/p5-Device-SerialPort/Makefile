# $NetBSD: Makefile,v 1.16 2005/08/06 06:19:05 jlam Exp $
#

DISTNAME=	Device-SerialPort-0.12
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dse
PKGREVISION=	2
CATEGORIES=	comms perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Device/}

MAINTAINER=	damon@brodiefamily.org
HOMEPAGE=	http://members.aol.com/Bbirthisel/alpha.html
COMMENT=	POSIX-based Perl module to control your serial port

DEPENDS+=	p5-perl-headers-${OS_VERSION}{,nb*}:../../devel/p5-perl-headers

PERL5_PACKLIST=		auto/Device/SerialPort/.packlist

MAKE_PARAMS=	${DEFAULT_SERIAL_DEVICE}

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
