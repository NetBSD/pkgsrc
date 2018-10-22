# $NetBSD: Makefile,v 1.1 2018/10/22 14:39:55 schmonz Exp $

DISTNAME=		Graph-Easy-0.76
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		graphics perl5
MASTER_SITES=		https://cpan.metacpan.org/authors/id/S/SH/SHLOMIF/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Graph-Easy
COMMENT=		Convert or render graphs as ASCII, HTML, SVG or via Graphviz
LICENSE=		gnu-gpl-v2

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Graph/Easy/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
