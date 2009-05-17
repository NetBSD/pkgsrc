# $NetBSD: Makefile,v 1.1.1.1 2009/05/17 10:24:53 sno Exp $
#

DISTNAME=	LaTeX-Encode-0.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=LaTeX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/LaTeX-Encode/
COMMENT=	Encode characters for LaTeX formatting
LICENSE=	gnu-gpl-v2 # OR artistic

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/LaTeX/Encode/.packlist
REPLACE_PERL+=		scripts/build-character-table scripts/format-encoding-reference

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
