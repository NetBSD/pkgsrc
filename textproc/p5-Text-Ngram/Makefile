# $NetBSD: Makefile,v 1.2 2012/10/03 21:58:04 wiz Exp $
#

DISTNAME=	Text-Ngram-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-Ngram/
COMMENT=	Ngram analysis of text
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Text/Ngram/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
