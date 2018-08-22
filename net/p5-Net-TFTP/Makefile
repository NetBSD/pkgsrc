# $NetBSD: Makefile,v 1.34 2018/08/22 09:46:02 wiz Exp $

DISTNAME=	Net-TFTP-0.1901
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~gbarr/Net-TFTP/
COMMENT=	Perl5 module for TFTP transfers
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-SUPER-[0-9]*:../../devel/p5-SUPER
DEPENDS+=	p5-Test-MockModule-[0-9]*:../../devel/p5-Test-MockModule
DEPENDS+=	p5-Test-Warn-[0-9]*:../../devel/p5-Test-Warn

PERL5_PACKLIST=		auto/Net/TFTP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
