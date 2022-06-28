# $NetBSD: Makefile,v 1.21 2022/06/28 11:32:37 wiz Exp $

DISTNAME=	IPC-System-Simple-1.30
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IPC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/IPC-System-Simple
COMMENT=	Run commands simply, with detailed diagnostics
LICENSE=	${PERL5_LICENSE}

TEST_DEPENDS+=	p5-Test-NoWarnings-[0-9]*:../../devel/p5-Test-NoWarnings
TEST_DEPENDS+=	p5-BSD-Resource-[0-9]*:../../devel/p5-BSD-Resource

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/IPC/System/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
