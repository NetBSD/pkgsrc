# $NetBSD: Makefile,v 1.4 2017/06/05 14:24:54 ryoon Exp $

DISTNAME=	Unicode-CaseFold-1.00
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Unicode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~arodland/Unicode-CaseFold/
COMMENT=	Unicode case-folding for case-insensitive lookups
LICENSE=	${PERL5_LICENSE}

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Unicode/CaseFold/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
