# $NetBSD: Makefile,v 1.3 2001/11/26 06:49:54 jlam Exp $
#

DISTNAME=		SortVersions-1.1
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5sve
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Sort/}

MAINTAINER=		mcr@netbsd.org
#HOMEPAGE=	
COMMENT=		perl5 module for sorting of revision-like numbers

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Sort/Versions/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
