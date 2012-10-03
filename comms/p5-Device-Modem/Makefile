# $NetBSD: Makefile,v 1.22 2012/10/03 11:24:43 asau Exp $
#

DISTNAME=	Device-Modem-1.56
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dmd
CATEGORIES=	comms perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Device/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Device-Modem/
COMMENT=	Perl module to talk to modem devices connected via serial port
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Device-SerialPort>=0.19:../../comms/p5-Device-SerialPort

PERL5_PACKLIST=		auto/Device/Modem/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
