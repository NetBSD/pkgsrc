# $NetBSD: Makefile,v 1.8 2001/06/07 04:25:32 jlam Exp $

.include "../../lang/perl5/Makefile.common"

PKGNAME=	p5-Devel-DProf-20000000
CATEGORIES+=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	jlam@netbsd.org
COMMENT=	perl5 module for profiling perl programs

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Devel/DProf/.packlist

EXTRACT_ELEMENTS=	${DISTNAME}/ext/Devel/DProf
WRKSRC=			${WRKDIR}/${EXTRACT_ELEMENTS}

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
