# $NetBSD: Makefile,v 1.14 2023/07/06 09:41:14 wiz Exp $
#

DISTNAME=	Regexp-Common-net-CIDR-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Regexp/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Regexp-Common-net-CIDR
COMMENT=	Provide patterns for CIDR blocks
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Regexp-Common-[0-9]*:../../textproc/p5-Regexp-Common

PERL5_PACKLIST=	auto/Regexp/Common/net/CIDR/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
