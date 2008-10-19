# $NetBSD: Makefile,v 1.4 2008/10/19 19:17:57 he Exp $
#

DISTNAME=	Module-Starter-1.470
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-Starter/
COMMENT=	Perl 5 module acting as a simple starter kit for any module

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Module/Starter/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
