# $NetBSD: Makefile,v 1.4 2001/09/29 06:24:06 jlam Exp $
#

DISTNAME=	Devel-Symdump-2.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	packages@netbsd.org
COMMENT=	perl5 module for inspecting perl's symtable/class hiers

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Devel/Symdump/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
