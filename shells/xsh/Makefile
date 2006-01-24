# $NetBSD: Makefile,v 1.9 2006/01/24 07:32:33 wiz Exp $

DISTNAME=	XML-XSH-1.8.2
PKGNAME=	${DISTNAME:S/XML-XSH/xsh/}
PKGREVISION=	3
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xsh/}

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://xsh.sourceforge.net/
COMMENT=	XML Editing Shell

DEPENDS+=	p5-Parse-RecDescent>=1.94:../../devel/p5-Parse-RecDescent
DEPENDS+=	p5-Term-ReadLine>=1.12:../../devel/p5-Term-ReadLine
DEPENDS+=	p5-XML-LibXML>=1.31:../../textproc/p5-XML-LibXML
DEPENDS+=	p5-XML-LibXML-Iterator-[0-9]*:../../textproc/p5-XML-LibXML-Iterator
DEPENDS+=	p5-XML-NodeFilter-[0-9]*:../../textproc/p5-XML-NodeFilter
DEPENDS+=	p5-XML-LibXML-XPathContext-[0-9]*:../../textproc/p5-XML-LibXML-XPathContext

USE_TOOLS+=	gmake
PKG_SHELL=	bin/xsh

PERL5_PACKLIST= auto/XML/XSH/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
