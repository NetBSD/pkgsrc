# $NetBSD: Makefile,v 1.18 2023/07/06 09:40:33 wiz Exp $

DISTNAME=	Module-Path-0.19
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Module-Path
COMMENT=	Perl5 module to get the full path to a locally installed module
LICENSE=	${PERL5_LICENSE}

REPLACE_PERL+=	bin/mpath

PERL5_PACKLIST=		auto/Module/Path/.packlist

TOOL_DEPENDS+=	p5-Devel-FindPerl-[0-9]*:../../devel/p5-Devel-FindPerl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
