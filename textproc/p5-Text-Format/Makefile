# $NetBSD: Makefile,v 1.1.1.1 2003/03/04 17:41:42 seb Exp $
#

DISTNAME=       Text-Format0.52
PKGNAME=        p5-Text-Format-0.52
SVR4_PKGNAME=	p5tfo
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	sketch@rd.bbc.co.uk
HOMEPAGE=	http://search.cpan.org/search?module=Text::Format
COMMENT=	Provide perl5 formatting functions on plain text

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Text/Format/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
