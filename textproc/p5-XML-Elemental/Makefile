# $NetBSD: Makefile,v 1.1.1.1 2008/07/15 23:07:03 rhaen Exp $
#

DISTNAME=	XML-Elemental-2.1
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~tima/XML-Elemental/
COMMENT=	Simplistic and perlish handling of XML data

DEPENDS+=	p5-Task-Weaken>=1.02:../../devel/p5-Task-Weaken
DEPENDS+=	p5-XML-SAX>=0:../../textproc/p5-XML-SAX

PKG_DESTDIR_SUPPORT=	user-destdir
PERL5_PACKLIST=	auto/XML/Elemental/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
