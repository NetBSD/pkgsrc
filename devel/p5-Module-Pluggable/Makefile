# $NetBSD: Makefile,v 1.31 2020/08/31 18:08:24 wiz Exp $
#

DISTNAME=	Module-Pluggable-5.2
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

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
