# $NetBSD: Makefile,v 1.3 2001/09/27 23:18:45 jlam Exp $
#

DISTNAME=	XML-DOM-1.31
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Extend XML::Parser to build DOM Level 1 compliant data structure

DEPENDS+=	p5-Parse-Yapp-[0-9]*:../../devel/p5-Parse-Yapp
DEPENDS+=	p5-libxml-[0-9]*:../../textproc/p5-libxml
DEPENDS+=	p5-XML-RegExp-[0-9]*:../../textproc/p5-XML-RegExp

CONFLICTS+=	p5-libxml-enno-[0-9]*

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/XML-DOM/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
