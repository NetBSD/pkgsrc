# $NetBSD: Makefile,v 1.1.1.1 2002/09/01 22:39:23 kim Exp $
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

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Inline/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
