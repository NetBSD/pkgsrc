# $NetBSD: Makefile,v 1.5 2003/06/02 01:16:32 jschauma Exp $
#

DISTNAME=       Text-Wrapper-1.000
PKGNAME=        p5-Text-Wrapper-1.0
SVR4_PKGNAME=	p5twr
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	tech-pkg@netbsd.org
COMMENT=	perl5 module that provides simple word wrapping

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Text/Wrapper/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
