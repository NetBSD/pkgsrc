# $NetBSD: Makefile,v 1.19 2021/05/24 19:50:42 wiz Exp $

DISTNAME=	File-Save-Home-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/File-Save-Home
COMMENT=	Place file safely under user home directory
LICENSE=	${PERL5_LICENSE}

# TEST_DEPENDS
BUILD_DEPENDS+=	p5-String-Random-[0-9]*:../../security/p5-String-Random

PERL5_PACKLIST=		auto/File/Save/Home/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
