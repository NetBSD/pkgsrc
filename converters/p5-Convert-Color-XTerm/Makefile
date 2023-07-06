# $NetBSD: Makefile,v 1.2 2023/07/06 09:38:14 wiz Exp $

DISTNAME=	Convert-Color-XTerm-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Convert-Color-XTerm
COMMENT=	Indexed colors used by XTerm
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Convert-Color-[0-9]*:../../converters/p5-Convert-Color

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Convert/Color/XTerm/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
