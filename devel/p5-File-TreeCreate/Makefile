# $NetBSD: Makefile,v 1.1 2023/06/27 07:56:15 wen Exp $

DISTNAME=	File-TreeCreate-0.0.1
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/File-TreeCreate
COMMENT=	Recursively create a directory tree
LICENSE=	mit

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/File/TreeCreate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
