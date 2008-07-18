# $NetBSD: Makefile,v 1.3 2008/07/18 12:48:31 rhaen Exp $
#

DISTNAME=	Module-Starter-1.470
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-Starter/
COMMENT=	Perl 5 module acting as a simple starter kit for any module

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Module/Starter/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
