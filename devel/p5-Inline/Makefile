# $NetBSD: Makefile,v 1.2 2002/10/20 23:35:10 seb Exp $
#

DISTNAME=     	Inline-0.43
PKGNAME=       	p5-${DISTNAME}
SVR4_PKGNAME=	p5inl
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Inline/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/Inline/Inline.html
COMMENT=	perl5 module for writing Perl subroutines in other languages

DEPENDS+=	p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5
DEPENDS+=	p5-Parse-RecDescent-[0-9]*:../../devel/p5-Parse-RecDescent

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Inline/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
