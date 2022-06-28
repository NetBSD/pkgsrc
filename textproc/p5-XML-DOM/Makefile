# $NetBSD: Makefile,v 1.44 2022/06/28 11:36:39 wiz Exp $

DISTNAME=	XML-DOM-1.46
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Extend XML::Parser to build DOM Level 1 compliant data structure

DEPENDS+=	p5-XML-Parser>=2.30:../../textproc/p5-XML-Parser
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-libxml-[0-9]*:../../textproc/p5-libxml
DEPENDS+=	p5-XML-RegExp-[0-9]*:../../textproc/p5-XML-RegExp

CONFLICTS+=	p5-libxml-enno-[0-9]*

PERL5_PACKLIST=		auto/XML/DOM/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
