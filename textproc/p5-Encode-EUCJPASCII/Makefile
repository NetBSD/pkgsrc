# $NetBSD: Makefile,v 1.3 2019/06/30 20:16:48 nia Exp $
#

DISTNAME=	Encode-EUCJPASCII-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Encode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Encode-EUCJPASCII
COMMENT=	eucJP-ascii - An eucJP-open mapping
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Encode/EUCJPASCII/.packlist

.include "../../textproc/p5-Encode/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
