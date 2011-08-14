# $NetBSD: Makefile,v 1.20 2011/08/14 15:14:10 obache Exp $

DISTNAME=	Text-Autoformat-1.669002
PKGNAME=	p5-${DISTNAME:S/669002/669.002/}
PKGREVISION=	2
SVR4_PKGNAME=	p5tau
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-Autoformat/
COMMENT=	Perl module for text wrapping and reformatting
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Text-Reform>=1.11:../../textproc/p5-Text-Reform

PERL5_PACKLIST=		auto/Text/Autoformat/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
