# $NetBSD: Makefile,v 1.16 2022/06/28 11:32:37 wiz Exp $
#

DISTNAME=		IPC-Signal-1.00
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		13
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=IPC/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/IPC-Signal
COMMENT=		Perl5 extension to deal with signals
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/IPC/Signal/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
