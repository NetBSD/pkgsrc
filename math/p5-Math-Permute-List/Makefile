# $NetBSD: Makefile,v 1.2 2012/09/11 23:04:27 asau Exp $

DISTNAME=	Math-Permute-List-1.004
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Math-Permute-List/
COMMENT=	Permute a list
LICENSE=	${PERL5_LICENSE}

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Math/Permute/List/.packlist

post-extract:
	${CHMOD} -R a+rx ${WRKSRC}
	${CHMOD} -R u+w ${WRKSRC}

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
