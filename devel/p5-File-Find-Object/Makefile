# $NetBSD: Makefile,v 1.1 2015/08/22 14:16:37 mef Exp $

DISTNAME=	File-Find-Object-v0.2.13
PKGNAME=	p5-${DISTNAME:S/-v/-/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~shlomif/File-Find-Object/lib/File/Find/Object.pm
COMMENT=	Object-oriented and iterative replacement for File::Find
LICENSE=	artistic-2.0# TODO: (see mk/license.mk)

# TODO: Look for the dependencies in Build.PL.

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/File/Find/Object/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
