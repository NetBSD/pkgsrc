# $NetBSD: Makefile,v 1.1.1.1 2004/07/30 12:56:39 cube Exp $

DISTNAME=	Module-Versions-Report-1.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Extension to report versions of all modules in memory

USE_BUILDLINK3=		YES
USE_LANGUAGES=		# empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Module-Versions-Report/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
