# $NetBSD: Makefile,v 1.2 2002/10/07 22:34:26 seb Exp $
#

DISTNAME=	Font-TTF-0.28
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Font/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Perl module for TrueType font hacking

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Font/TTF/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
