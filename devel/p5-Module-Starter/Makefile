# $NetBSD: Makefile,v 1.9 2011/08/14 12:26:19 obache Exp $
#

DISTNAME=	Module-Starter-1.54
PKGNAME=	p5-${DISTNAME}0
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}
LICENSE=	${PERL5_LICENSE}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-Starter/
COMMENT=	Perl 5 module acting as a simple starter kit for any module
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Module/Starter/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
