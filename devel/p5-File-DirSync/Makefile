# $NetBSD: Makefile,v 1.29 2022/06/28 11:32:24 wiz Exp $

DISTNAME=	File-DirSync-1.22
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	14
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/File-DirSync
COMMENT=	Perl5 module to synchronize two directories rapidly
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/File/DirSync/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
