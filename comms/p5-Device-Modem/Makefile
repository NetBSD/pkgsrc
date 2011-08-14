# $NetBSD: Makefile,v 1.19 2011/08/14 07:43:02 obache Exp $
#

DISTNAME=	Device-Modem-1.53
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dmd
PKGREVISION=	1
CATEGORIES=	comms perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Device/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Device-Modem/
COMMENT=	Perl module to talk to modem devices connected via serial port
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Device-SerialPort>=0.19:../../comms/p5-Device-SerialPort

PERL5_PACKLIST=		auto/Device/Modem/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
