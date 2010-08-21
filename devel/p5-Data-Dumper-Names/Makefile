# $NetBSD: Makefile,v 1.2 2010/08/21 16:33:30 seb Exp $
#

DISTNAME=	Data-Dumper-Names-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Data::Dumper::Names
COMMENT=	Dump variables with names (no source filter)
LICENSE=	artistic-2.0

DEPENDS+=	p5-PadWalker>0.13:../../devel/p5-PadWalker

PKG_DESTDIR_SUPPORT=	user-destdir
PERL5_MODULE_TYPE= Module::Build

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Data/Dumper/Names/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
