# $NetBSD: Makefile,v 1.5 2011/08/14 12:26:46 obache Exp $

DISTNAME=	Tie-RefHash-1.38
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tie/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Tie-RefHash/
COMMENT=	Use references as hash keys

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Tie/RefHash/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
