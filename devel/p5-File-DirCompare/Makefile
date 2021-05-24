# $NetBSD: Makefile,v 1.16 2021/05/24 19:50:40 wiz Exp $

DISTNAME=	File-DirCompare-0.7
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/File-DirCompare
COMMENT=	Perl module to compare two directories using callbacks
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/File/DirCompare/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
