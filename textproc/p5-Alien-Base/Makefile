# $NetBSD: Makefile,v 1.1 2016/07/30 13:16:23 mef Exp $

DISTNAME=	Alien-Base-0.004
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/J/JB/JBERGER/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~jberger/Alien-Base-0.004/lib/Alien/Base/ModuleBuild.pm
COMMENT=	Module::Build subclass for building Alien:: modules/libraries
LICENSE=	${PERL5_LICENSE}

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=         auto/Alien/Base/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
