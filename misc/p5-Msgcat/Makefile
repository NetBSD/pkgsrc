# $NetBSD: Makefile,v 1.10 2005/07/13 18:01:34 jlam Exp $
#

DISTNAME=		Msgcat-1.01
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5lco
PKGREVISION=		1
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Locale/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=
COMMENT=		Perl5 module to use the message catalog functions

WRKSRC=			${WRKDIR}/Msgcat
PERL5_PACKLIST=		auto/Locale/Msgcat/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
