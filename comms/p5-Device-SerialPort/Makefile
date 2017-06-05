# $NetBSD: Makefile,v 1.30 2017/06/05 14:22:20 ryoon Exp $
#

DISTNAME=	Device-SerialPort-1.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	comms perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Device/}

MAINTAINER=	damon@brodiefamily.org
HOMEPAGE=	http://members.aol.com/Bbirthisel/alpha.html
COMMENT=	POSIX-based Perl module to control your serial port
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-perl-headers-${OS_VERSION}{,nb*}:../../devel/p5-perl-headers

PERL5_PACKLIST=		auto/Device/SerialPort/.packlist

MAKE_PARAMS=	${DEFAULT_SERIAL_DEVICE}

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
