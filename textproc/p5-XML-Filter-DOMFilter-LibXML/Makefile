# $NetBSD: Makefile,v 1.6 2012/10/03 21:58:09 wiz Exp $

DISTNAME=	XML-Filter-DOMFilter-LibXML-0.02
PKGNAME=	p5-${DISTNAME}
#SVR4_PKGNAME=
PKGREVISION=	4
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-Filter-DOMFilter-LibXML/
COMMENT=	Perl5 module SAX filter allowing DOM processing

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-XML-LibXML>=1.53:../../textproc/p5-XML-LibXML

USE_LANGUAGES=		# empty
PERL5_PACKLIST=	auto/XML/Filter/DOMFilter/LibXML/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
