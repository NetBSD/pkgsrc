# $NetBSD: Makefile,v 1.2 2002/02/07 23:07:28 jlam Exp $

DISTNAME=	Term-ReadLine-Gnu-1.11
PKGNAME=	p5-Term-ReadLine-1.11
SVR4_PKGNAME=	p5trl
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/Term-ReadLine-Gnu/
COMMENT=	interface to the GNU Readline Library

USE_BUILDLINK_ONLY=	yes
USE_GNU_READLINE=	yes
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Term/ReadLine/Gnu/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../devel/readline/buildlink.mk"
.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
