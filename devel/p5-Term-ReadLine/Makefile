# $NetBSD: Makefile,v 1.14 2005/07/13 18:01:29 jlam Exp $

DISTNAME=	Term-ReadLine-Gnu-1.14
PKGNAME=	p5-${DISTNAME:S/-Gnu//}
PKGREVISION=	2
SVR4_PKGNAME=	p5trl
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/Term-ReadLine-Gnu/
COMMENT=	Interface to the GNU Readline Library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_GNU_READLINE=	yes
PERL5_PACKLIST=		auto/Term/ReadLine/Gnu/.packlist

.include "../../devel/readline/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
