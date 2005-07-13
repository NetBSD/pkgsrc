# $NetBSD: Makefile,v 1.10 2005/07/13 18:01:26 jlam Exp $
#

DISTNAME=     	Inline-0.44
PKGNAME=       	p5-${DISTNAME}
SVR4_PKGNAME=	p5inl
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Inline/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/Inline/Inline.html
COMMENT=	Perl5 module for writing Perl subroutines in other languages

DEPENDS+=	p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5
DEPENDS+=	p5-Parse-RecDescent-[0-9]*:../../devel/p5-Parse-RecDescent

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Inline/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
