# $NetBSD: Makefile,v 1.5 2003/06/02 01:16:34 jschauma Exp $

DISTNAME=       Text-Autoformat-1.04
PKGNAME=        p5-${DISTNAME}
SVR4_PKGNAME=	p5tau
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.cs.monash.edu.au/~damian/
COMMENT=	perl module for text wrapping and reformatting

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Text/Autoformat/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
