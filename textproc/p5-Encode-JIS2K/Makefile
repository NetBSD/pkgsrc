# $NetBSD: Makefile,v 1.4 2019/08/11 13:23:28 wiz Exp $
#

DISTNAME=	Encode-JIS2K-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Encode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Encode-JIS2K
COMMENT=	JIS X 0212 (aka JIS 2000) Encodings
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Encode/JIS2K/.packlist

.include "../../textproc/p5-Encode/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
