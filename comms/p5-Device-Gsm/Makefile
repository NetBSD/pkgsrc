# $NetBSD: Makefile,v 1.41 2023/07/06 09:38:13 wiz Exp $
#

DISTNAME=	Device-Gsm-1.61
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	comms perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Device/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Device-Gsm
COMMENT=	Perl module to interface GSM cellular / modems
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Device-Modem>=1.47:../../comms/p5-Device-Modem
DEPENDS+=	p5-Device-SerialPort-[0-9]*:../../comms/p5-Device-SerialPort

PERL5_PACKLIST=		auto/Device/Gsm/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
