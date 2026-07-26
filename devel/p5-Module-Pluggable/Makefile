# $NetBSD: Makefile,v 1.43 2026/07/26 17:54:12 wiz Exp $

DISTNAME=	Module-Pluggable-6.4
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SI/SIMONW/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Module-Pluggable
COMMENT=	Automatically adds the ability to have plugins to modules
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Module/Pluggable/.packlist

post-extract:
	 ${FIND} ${WRKSRC} -type f -name "*.pm" -print | ${XARGS} ${CHMOD} -x

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
