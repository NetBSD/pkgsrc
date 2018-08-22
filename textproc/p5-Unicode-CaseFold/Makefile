# $NetBSD: Makefile,v 1.6 2018/08/22 09:47:04 wiz Exp $

DISTNAME=	Unicode-CaseFold-1.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
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
