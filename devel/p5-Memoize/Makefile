# $NetBSD: Makefile,v 1.1.1.1 2001/04/06 22:42:06 mjl Exp $
#

DISTNAME=	Memoize-0.62
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Memoize/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://perl.plover.com/
COMMENT=	Transparently speed up functions by caching return values

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Memoize/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
