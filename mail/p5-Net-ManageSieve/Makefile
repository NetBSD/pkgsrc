# $NetBSD: Makefile,v 1.25 2026/07/16 19:04:08 wiz Exp $

DISTNAME=	Net-ManageSieve-0.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Net-ManageSieve
COMMENT=	ManageSieve Protocol Client
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Net/ManageSieve/.packlist

post-patch:
	rm ${WRKSRC}/lib/Net/*.orig

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
