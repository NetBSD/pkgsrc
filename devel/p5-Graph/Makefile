# $NetBSD: Makefile,v 1.1.1.1 2002/08/28 19:28:53 seb Exp $

DISTNAME=	Graph-0.201
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Graph/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Perl module for graph operations

DEPENDS+=		p5-Heap>=0.50:../../devel/p5-Heap

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Graph/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
