# $NetBSD: Makefile,v 1.22 2006/03/04 21:30:49 jlam Exp $
#

DISTNAME=	XML-DOM-1.43
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
SVR4_PKGNAME=	p5xdo
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Extend XML::Parser to build DOM Level 1 compliant data structure

DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-libxml-[0-9]*:../../textproc/p5-libxml
DEPENDS+=	p5-XML-RegExp-[0-9]*:../../textproc/p5-XML-RegExp

CONFLICTS+=	p5-libxml-enno-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/XML-DOM/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
