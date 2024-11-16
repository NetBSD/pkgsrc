# $NetBSD: Makefile,v 1.25 2024/11/16 12:06:23 wiz Exp $

DISTNAME=	LaTeX-Encode-0.092.0
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=LaTeX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/LaTeX-Encode
COMMENT=	Encode characters for LaTeX formatting
LICENSE=	gnu-gpl-v2 # OR artistic

DEPENDS+=	p5-Readonly>=0:../../devel/p5-Readonly
# TEST_DEPENDS
TOOL_DEPENDS+=	p5-Carp-Always-[0-9]*:../../devel/p5-Carp-Always

PERL5_PACKLIST=		auto/LaTeX/Encode/.packlist
REPLACE_PERL+=		scripts/format-encoding-reference

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
