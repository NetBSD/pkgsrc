# $NetBSD: Makefile,v 1.6 2008/10/19 19:18:56 he Exp $

DISTNAME=	Text-Diff-HTML-0.05
PKGNAME=	p5-${DISTNAME}
# PKGREVISION=	2
PKGREVISION=	1
CATEGORIES=	perl5 textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DW/DWHEELER/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-Diff-HTML/
COMMENT=	HTML formatting class for Text::Diff

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Text-Diff>=0.11:../../textproc/p5-Text-Diff
DEPENDS+=	p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Text/Diff/HTML/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
