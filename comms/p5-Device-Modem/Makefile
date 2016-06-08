# $NetBSD: Makefile,v 1.29 2016/06/08 19:22:19 wiz Exp $

DISTNAME=	Device-Modem-1.57
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
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
