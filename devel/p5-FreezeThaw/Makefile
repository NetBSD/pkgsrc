# $NetBSD: Makefile,v 1.5 2003/06/02 01:20:30 jschauma Exp $
#

DISTNAME=	FreezeThaw-0.41
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5frt
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=FreezeThaw/}

MAINTAINER=	tech-pkg@netbsd.org
COMMENT=	converting Perl structures to strings and back

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/FreezeThaw/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
