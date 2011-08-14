# $NetBSD: Makefile,v 1.18 2011/08/14 15:14:17 obache Exp $

DISTNAME=	XML-Encoding-2.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-Encoding/
COMMENT=	Perl module for parsing XML encoding maps
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-XML-Parser>=2.18:../../textproc/p5-XML-Parser

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/XML/Encoding/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
