# $NetBSD: Makefile,v 1.4 2003/06/02 01:19:44 jschauma Exp $
#

DISTNAME=	Font-TTF-0.34
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Font/}

MAINTAINER=	tech-pkg@netbsd.org
COMMENT=	Perl module for TrueType font hacking

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Font/TTF/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
