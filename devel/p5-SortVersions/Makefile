# $NetBSD: Makefile,v 1.1 2001/10/02 01:25:35 mcr Exp $
#

DISTNAME=		SortVersions-1.1
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Sort/}

MAINTAINER=		mcr@netbsd.org
#HOMEPAGE=	
COMMENT=		perl5 module for sorting of revision-like numbers

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Sort/Versions/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
