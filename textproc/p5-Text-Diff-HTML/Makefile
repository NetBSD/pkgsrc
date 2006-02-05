# $NetBSD: Makefile,v 1.2 2006/02/05 23:11:04 joerg Exp $

DISTNAME=	Text-Diff-HTML-0.04
PKGNAME=	p5-${DISTNAME}
# PKGREVISION=	2
PKGREVISION=	1
CATEGORIES=	perl5 textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DW/DWHEELER/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	HTML formatting class for Text::Diff

DEPENDS+=	p5-Text-Diff>=0.11:../../textproc/p5-Text-Diff
DEPENDS+=	p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Text/Diff/HTML/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
