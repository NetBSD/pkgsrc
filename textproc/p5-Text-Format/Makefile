# $NetBSD: Makefile,v 1.10 2008/10/19 19:18:56 he Exp $
#

DISTNAME=	Text-Format0.52
PKGNAME=	p5-Text-Format-0.52
PKGREVISION=	3
SVR4_PKGNAME=	p5tfo
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	sketch@NetBSD.org
HOMEPAGE=	http://search.cpan.org/search?module=Text::Format
COMMENT=	Provide perl5 formatting functions on plain text

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Text/Format/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
