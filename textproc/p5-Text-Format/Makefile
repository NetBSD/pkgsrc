# $NetBSD: Makefile,v 1.11 2010/08/21 16:36:05 seb Exp $
#

DISTNAME=	Text-Format0.52
PKGNAME=	p5-Text-Format-0.52
PKGREVISION=	4
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
