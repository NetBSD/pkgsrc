# $NetBSD: Makefile,v 1.15 2023/06/27 08:06:37 wen Exp $

DISTNAME=	File-Find-Object-0.3.7
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/distribution/File-Find-Object/lib/File/Find/Object.pm
COMMENT=	Object-oriented and iterative replacement for File::Find
LICENSE=	artistic-2.0

TEST_DEPENDS+=	p5-Class-XSAccessor-[0-9]*:../../devel/p5-Class-XSAccessor
TEST_DEPENDS+=	p5-Test-File-[0-9]*:../../devel/p5-Test-File
TEST_DEPENDS+=	p5-File-TreeCreate-[0-9]*:../../devel/p5-File-TreeCreate

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/File/Find/Object/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
