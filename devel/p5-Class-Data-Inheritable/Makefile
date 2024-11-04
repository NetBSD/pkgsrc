# $NetBSD: Makefile,v 1.33 2024/11/04 19:08:16 pgoyette Exp $

EXTRACT_USING=	gtar	# XXX avoid extended attributes in distfile

DISTNAME=	Class-Data-Inheritable-0.10
PKGNAME=	p5-${DISTNAME}
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
