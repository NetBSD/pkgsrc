# $NetBSD: Makefile,v 1.10 2008/02/08 14:51:25 rhaen Exp $

DISTNAME=	XML-Encoding-2.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SH/SHAY/}


MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-Encoding-2.01/
COMMENT=	Perl module for parsing XML encoding maps

DEPENDS+=	p5-XML-Parser>=2.18:../../textproc/p5-XML-Parser
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/XML/Encoding/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
