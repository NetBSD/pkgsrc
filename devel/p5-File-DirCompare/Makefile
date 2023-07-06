# $NetBSD: Makefile,v 1.18 2023/07/06 09:39:09 wiz Exp $

DISTNAME=	File-DirCompare-0.7
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/File-DirCompare
COMMENT=	Perl module to compare two directories using callbacks
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/File/DirCompare/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
