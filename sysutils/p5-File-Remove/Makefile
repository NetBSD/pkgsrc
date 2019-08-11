# $NetBSD: Makefile,v 1.33 2019/08/11 13:23:11 wiz Exp $

DISTNAME=	File-Remove-1.58
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	perl5 sysutils
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/File-Remove
COMMENT=	Remove files and directories
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/File/Remove/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
