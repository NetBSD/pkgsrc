# $NetBSD: Makefile,v 1.16 2006/03/04 21:29:24 jlam Exp $

DISTNAME=	Term-ReadLine-Gnu-1.14
PKGNAME=	p5-${DISTNAME:S/-Gnu//}
PKGREVISION=	3
SVR4_PKGNAME=	p5trl
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/Term-ReadLine-Gnu/
COMMENT=	Interface to the GNU Readline Library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_GNU_READLINE=	yes
PERL5_PACKLIST=		auto/Term/ReadLine/Gnu/.packlist

.include "../../devel/readline/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
