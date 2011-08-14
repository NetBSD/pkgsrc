# $NetBSD: Makefile,v 1.5 2011/08/14 12:26:47 obache Exp $

DISTNAME=	Tie-ToObject-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tie/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Tie-ToObject/
COMMENT=	Tie to an existing object

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Tie/ToObject/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
