# $NetBSD: Makefile,v 1.4 2004/12/20 11:31:10 grant Exp $
#

DISTNAME=       Text-Format0.52
PKGNAME=        p5-Text-Format-0.52
SVR4_PKGNAME=	p5tfo
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	sketch@NetBSD.org
HOMEPAGE=	http://search.cpan.org/search?module=Text::Format
COMMENT=	Provide perl5 formatting functions on plain text

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Text/Format/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
