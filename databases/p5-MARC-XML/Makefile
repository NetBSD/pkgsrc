# $NetBSD: Makefile,v 1.14 2018/08/22 09:43:19 wiz Exp $

DISTNAME=	MARC-XML-1.0.4
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	converters perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/G/GM/GMCHARLT/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MARC-XML/
COMMENT=	Work with MARC data encoded as XML, SAX handler for parsing MARCXML
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-XML-LibXML-[0-9]*:../../textproc/p5-XML-LibXML
DEPENDS+=	p5-XML-SAX>=0.12:../../textproc/p5-XML-SAX
DEPENDS+=	p5-MARC-Record>=2.0:../../databases/p5-MARC-Record
DEPENDS+=	p5-MARC-Charset>=0.98:../../converters/p5-MARC-Charset

# TEST_DEPENDS
BUILD_DEPENDS+=	p5-Test-Warn-[0-9]*:../../devel/p5-Test-Warn

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MARC-XML/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
