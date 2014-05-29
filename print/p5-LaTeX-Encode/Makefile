# $NetBSD: Makefile,v 1.9 2014/05/29 23:37:16 wiz Exp $
#

DISTNAME=	LaTeX-Encode-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=LaTeX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/LaTeX-Encode/
COMMENT=	Encode characters for LaTeX formatting
LICENSE=	gnu-gpl-v2 # OR artistic

DEPENDS+=		p5-Readonly>=0:../../devel/p5-Readonly

PERL5_PACKLIST=		auto/LaTeX/Encode/.packlist
REPLACE_PERL+=		scripts/build-character-table scripts/format-encoding-reference

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
