# $NetBSD: Makefile,v 1.8 2003/06/02 01:20:32 jschauma Exp $
#

DISTNAME=	Devel-Symdump-2.01
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dsd
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	tech-pkg@netbsd.org
COMMENT=	perl5 module for inspecting perl's symtable/class hiers

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Devel/Symdump/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
