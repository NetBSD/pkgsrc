# $NetBSD: Makefile,v 1.14 2008/06/20 01:09:09 joerg Exp $
#

DISTNAME=	Device-Gsm-1.48
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dgs
CATEGORIES=	comms perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Device/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl module to interface GSM cellular / modems

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Device-Modem>=1.47:../../comms/p5-Device-Modem

PERL5_PACKLIST=		auto/Device/Gsm/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
