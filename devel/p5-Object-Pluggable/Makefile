# $NetBSD: Makefile,v 1.16 2022/06/28 11:32:58 wiz Exp $
#

DISTNAME=	Object-Pluggable-1.29
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Object/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Object-Pluggable
COMMENT=	Base class for creating plugin-enabled objects
LICENSE=	${PERL5_LICENSE}

#BUILD_DEPENDS+=	{perl>=5.10.1,p5-Pod-Parser>=1.36}:../../textproc/p5-Pod-Parser

DEPENDS+=	p5-Task-Weaken-[0-9]*:../../devel/p5-Task-Weaken

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Object/Pluggable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
