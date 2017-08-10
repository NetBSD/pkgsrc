# $NetBSD: Makefile,v 1.14 2017/08/10 14:00:11 wen Exp $
#

DISTNAME=	LaTeX-Encode-0.092.0
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=LaTeX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/LaTeX-Encode/
COMMENT=	Encode characters for LaTeX formatting
LICENSE=	gnu-gpl-v2 # OR artistic

DEPENDS+=		p5-Readonly>=0:../../devel/p5-Readonly
# for make test
BUILD_DEPENDS+=	p5-Carp-Always-[0-9]*:../../devel/p5-Carp-Always

PERL5_PACKLIST=		auto/LaTeX/Encode/.packlist
REPLACE_PERL+=		scripts/build-character-table scripts/format-encoding-reference

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
