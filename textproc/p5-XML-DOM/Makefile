# $NetBSD: Makefile,v 1.1.1.1 2001/08/10 12:47:39 mjl Exp $
#

DISTNAME=	XML-DOM-1.31
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Extend XML::Parser to build DOM Level 1 compliant data structure

DEPENDS+=	p5-Parse-Yapp-*:../../devel/p5-Parse-Yapp
DEPENDS+=	p5-libxml-*:../../textproc/p5-libxml
DEPENDS+=	p5-XML-RegExp-*:../../textproc/p5-XML-RegExp

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/XML-DOM/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
