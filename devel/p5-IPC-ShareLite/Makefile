# $NetBSD: Makefile,v 1.35 2025/07/04 08:45:58 wiz Exp $
#

DISTNAME=	IPC-ShareLite-0.17
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	16
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IPC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/IPC-ShareLite
COMMENT=	Light-weight interface to shared memory

USE_LANGUAGES=		c

PERL5_PACKLIST=		auto/IPC/ShareLite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
