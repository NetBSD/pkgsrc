# $NetBSD: Makefile,v 1.12 2011/08/14 12:26:19 obache Exp $
#

DISTNAME=	Module-Pluggable-3.9
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5mpl
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-Pluggable/
COMMENT=	Perl 5 module for automatically adding the ability to have plugins to modules

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Module/Pluggable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
