# $NetBSD: Makefile,v 1.30 2016/06/08 19:24:13 wiz Exp $

DISTNAME=	Net-TFTP-0.19
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~gbarr/Net-TFTP-0.17/
COMMENT=	Perl5 module for TFTP transfers
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Test-MockModule-[0-9]*:../../devel/p5-Test-MockModule

PERL5_PACKLIST=		auto/Net/TFTP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
