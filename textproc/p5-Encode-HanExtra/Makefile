# $NetBSD: Makefile,v 1.1 2017/08/01 13:13:17 markd Exp $
#

DISTNAME=	Encode-HanExtra-0.23
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Encode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Encode-HanExtra/
COMMENT=	Extra sets of Chinese encodings
LICENSE=	mit

PERL5_MODULE_TYPE=	Module::Install
PERL5_PACKLIST=		auto/Encode/HanExtra/.packlist

.include "../../textproc/p5-Encode/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
