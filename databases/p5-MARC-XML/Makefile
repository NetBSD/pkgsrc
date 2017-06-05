# $NetBSD: Makefile,v 1.12 2017/06/05 14:22:29 ryoon Exp $

DISTNAME=	MARC-XML-1.0.3
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MARC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MARC-XML/
COMMENT=	Work with MARC data encoded as XML, SAX handler for parsing MARCXML
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-XML-SAX>=0.12:../../textproc/p5-XML-SAX
DEPENDS+=	p5-MARC-Record>=2.0:../../databases/p5-MARC-Record
DEPENDS+=	p5-MARC-Charset>=0.98:../../converters/p5-MARC-Charset

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MARC-XML/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
