# $NetBSD: Makefile,v 1.16 2008/10/12 21:03:58 he Exp $
#

DISTNAME=	Device-Gsm-1.50
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dgs
CATEGORIES=	comms perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Device/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Device-Gsm/
COMMENT=	Perl module to interface GSM cellular / modems

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Device-Modem>=1.47:../../comms/p5-Device-Modem

PERL5_PACKLIST=		auto/Device/Gsm/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
