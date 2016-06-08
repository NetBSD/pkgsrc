# $NetBSD: Makefile,v 1.3 2016/06/08 19:22:55 wiz Exp $

DISTNAME=	File-Find-Object-v0.2.13
PKGNAME=	p5-${DISTNAME:S/-v/-/}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~shlomif/File-Find-Object/lib/File/Find/Object.pm
COMMENT=	Object-oriented and iterative replacement for File::Find
LICENSE=	artistic-2.0

BUILD_DEPENDS+=	p5-Class-XSAccessor-[0-9]*:../../devel/p5-Class-XSAccessor

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/File/Find/Object/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
