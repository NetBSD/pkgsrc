# $NetBSD: Makefile,v 1.2 2018/08/22 09:46:49 wiz Exp $
#

DISTNAME=	Encode-JIS2K-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Encode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Encode-JIS2K/
COMMENT=	JIS X 0212 (aka JIS 2000) Encodings
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Encode/JIS2K/.packlist

.include "../../textproc/p5-Encode/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
