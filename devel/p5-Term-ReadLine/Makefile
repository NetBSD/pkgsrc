# $NetBSD: Makefile,v 1.8 2003/12/11 17:27:24 erh Exp $

DISTNAME=	Term-ReadLine-Gnu-1.12
PKGNAME=	p5-Term-ReadLine-1.12
SVR4_PKGNAME=	p5trl
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/Term-ReadLine-Gnu/
COMMENT=	Interface to the GNU Readline Library

USE_BUILDLINK2=		yes
USE_GNU_READLINE=	yes
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Term/ReadLine/Gnu/.packlist

.include "../../devel/readline/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
