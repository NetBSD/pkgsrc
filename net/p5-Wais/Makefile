# $NetBSD: Makefile,v 1.6 2001/02/17 18:19:25 wiz Exp $
#

DISTNAME=	Wais-2.311
PKGNAME=	p5-Wais-2.311
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Wais/}

MAINTAINER=	bad@netbsd.org
COMMENT=	perl5 module for accessing WAIS servers

DEPENDS+=	freewais-sf-2.2.12:../../net/freewais-sf
DEPENDS+=	p5-Curses>=1.02:../../devel/p5-Curses

USE_PERL5=	# defined
PERL5_PACKLIST= ${PERL5_SITEARCH}/auto/Wais/.packlist

post-patch:
	${FIND} ${WRKSRC} -name "*.orig" -exec ${RM} -f {} \;

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
