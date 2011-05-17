# $NetBSD: Makefile,v 1.1.1.1 2011/05/17 10:33:38 dmcmahill Exp $

DISTNAME=	MARC-Charset-1.2
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/id/E/ES/ESUMMERS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MARC-Charset/
COMMENT=	Convert MARC-8 encoded strings to UTF-8
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-XML-SAX:../../textproc/p5-XML-SAX
DEPENDS+=	p5-Class-Accessor:../../devel/p5-Class-Accessor

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MARC/Charset/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
