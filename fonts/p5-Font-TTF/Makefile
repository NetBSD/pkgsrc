# $NetBSD: Makefile,v 1.7 2004/12/20 11:31:03 grant Exp $
#

DISTNAME=	Font-TTF-0.34
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Font/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl module for TrueType font hacking

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Font/TTF/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
