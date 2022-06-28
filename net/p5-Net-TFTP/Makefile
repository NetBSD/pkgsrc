# $NetBSD: Makefile,v 1.39 2022/06/28 11:35:14 wiz Exp $

DISTNAME=	Net-TFTP-0.1901
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Net-TFTP
COMMENT=	Perl5 module for TFTP transfers
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-SUPER-[0-9]*:../../devel/p5-SUPER
DEPENDS+=	p5-Test-MockModule-[0-9]*:../../devel/p5-Test-MockModule
DEPENDS+=	p5-Test-Warn-[0-9]*:../../devel/p5-Test-Warn

PERL5_PACKLIST=		auto/Net/TFTP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
