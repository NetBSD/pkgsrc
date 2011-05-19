# $NetBSD: Makefile,v 1.2 2011/05/19 05:08:38 obache Exp $

DISTNAME=	Biblio-EndnoteStyle-0.05
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Biblio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Biblio-EndnoteStyle/
COMMENT=	reference formatting using Endnote-like templates
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Biblio/EndnoteStyle/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
