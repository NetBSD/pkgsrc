# $NetBSD: Makefile,v 1.1.1.1 2003/01/13 12:56:50 manu Exp $
#

DISTNAME=		Msgcat-1.01
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5lco
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Locale/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=
COMMENT=		perl5 module to use the message catalog functions

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Locale/Msgcat/.packlist

WRKSRC=			${WRKDIR}/Msgcat

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
