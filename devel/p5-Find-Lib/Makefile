# $NetBSD: Makefile,v 1.2 2015/06/12 10:49:16 wiz Exp $

DISTNAME=	Find-Lib-1.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Find/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~yannk/Find-Lib/
COMMENT=	Helper to smartly find libs to use in the filesystem tree
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Find/Lib/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
