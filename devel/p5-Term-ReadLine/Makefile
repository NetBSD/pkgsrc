# $NetBSD: Makefile,v 1.4 2002/10/20 23:35:09 seb Exp $

DISTNAME=	Term-ReadLine-Gnu-1.12
PKGNAME=	p5-Term-ReadLine-1.12
SVR4_PKGNAME=	p5trl
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/Term-ReadLine-Gnu/
COMMENT=	interface to the GNU Readline Library

USE_BUILDLINK2=		yes
USE_GNU_READLINE=	yes
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Term/ReadLine/Gnu/.packlist

.include "../../devel/readline/buildlink2.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
