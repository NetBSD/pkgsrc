# $NetBSD: Makefile,v 1.11 2004/10/03 00:13:32 tv Exp $

DISTNAME=	Term-ReadLine-Gnu-1.14
PKGNAME=	p5-${DISTNAME:S/-Gnu//}
PKGREVISION=	1
SVR4_PKGNAME=	p5trl
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/Term-ReadLine-Gnu/
COMMENT=	Interface to the GNU Readline Library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_GNU_READLINE=	yes
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Term/ReadLine/Gnu/.packlist

.include "../../devel/readline/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
