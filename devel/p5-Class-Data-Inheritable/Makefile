# $NetBSD: Makefile,v 1.25 2019/08/11 13:19:00 wiz Exp $

DISTNAME=	Class-Data-Inheritable-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Class-Data-Inheritable
COMMENT=	Inheritable, overridable class data
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# none
PERL5_PACKLIST=		auto/Class/Data/Inheritable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
