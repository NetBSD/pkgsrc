# $NetBSD: Makefile,v 1.7 2003/07/21 17:27:44 martti Exp $
#

DISTNAME=       Text-Wrapper-1.000
PKGNAME=        p5-Text-Wrapper-1.0
SVR4_PKGNAME=	p5twr
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 module that provides simple word wrapping

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Text/Wrapper/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
