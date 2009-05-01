# $NetBSD: Makefile,v 1.9 2009/05/01 21:28:16 sno Exp $

DISTNAME=	Text-Tabs+Wrap-2009.0305
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~muir/${DISTNAME}
COMMENT=	Line wrapping to form simple paragraphs

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Text/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
