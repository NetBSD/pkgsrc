# $NetBSD: Makefile,v 1.6 2012/10/03 21:58:08 wiz Exp $
#

DISTNAME=	XML-Elemental-2.11
PKGNAME=	p5-${DISTNAME:S/11/1.1/}
PKGREVISION=	3
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~tima/XML-Elemental/
COMMENT=	Simplistic and perlish handling of XML data
LICENSE=	artistic

DEPENDS+=	p5-XML-SAX>=0:../../textproc/p5-XML-SAX
BUILD_DEPENDS+=	p5-Task-Weaken>=1.02:../../devel/p5-Task-Weaken

PKG_DESTDIR_SUPPORT=	user-destdir
PERL5_PACKLIST=	auto/XML/Elemental/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
