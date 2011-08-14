# $NetBSD: Makefile,v 1.18 2011/08/14 12:26:48 obache Exp $
#

DISTNAME=	Variable-Magic-0.43
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Variable/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Variable-Magic/
COMMENT=	Perl 5 module to associate user-defined magic to variables
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c

PERL5_PACKLIST=	auto/Variable/Magic/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
