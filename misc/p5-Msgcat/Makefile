# $NetBSD: Makefile,v 1.12 2005/12/05 20:50:40 rillig Exp $
#

DISTNAME=		Msgcat-1.01
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5lco
PKGREVISION=		2
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Locale/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Perl5 module to use the message catalog functions

WRKSRC=			${WRKDIR}/Msgcat
PERL5_PACKLIST=		auto/Locale/Msgcat/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
