# $NetBSD: Makefile,v 1.17 2019/06/30 20:16:35 nia Exp $

DISTNAME=	LaTeX-Encode-0.092.0
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=LaTeX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/LaTeX-Encode
COMMENT=	Encode characters for LaTeX formatting
LICENSE=	gnu-gpl-v2 # OR artistic

DEPENDS+=		p5-Readonly>=0:../../devel/p5-Readonly
# TEST_DEPENDS
BUILD_DEPENDS+=	p5-Carp-Always-[0-9]*:../../devel/p5-Carp-Always

PERL5_PACKLIST=		auto/LaTeX/Encode/.packlist
REPLACE_PERL+=		scripts/format-encoding-reference

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
