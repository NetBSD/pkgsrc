# $NetBSD: Makefile,v 1.8 2011/08/14 12:26:16 obache Exp $

DISTNAME=	MRO-Compat-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/F/FL/FLORA/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?MRO::Compat
COMMENT=	MRO::* interface compatibility for Perls < 5.9.5
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MRO/Compat/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
