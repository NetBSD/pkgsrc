# $NetBSD: Makefile,v 1.11 2010/08/21 16:36:07 seb Exp $

DISTNAME=	Text-Tabs+Wrap-2009.0305
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~muir/${DISTNAME}
COMMENT=	Line wrapping to form simple paragraphs

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Text/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
