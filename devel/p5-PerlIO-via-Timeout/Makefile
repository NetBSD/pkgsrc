# $NetBSD: Makefile,v 1.11 2023/07/06 09:39:53 wiz Exp $

DISTNAME=	PerlIO-via-Timeout-0.32
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PerlIO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/PerlIO-via-Timeout
COMMENT=	PerlIO layer to add read and write timeouts to a handle
LICENSE=	${PERL5_LICENSE}

TOOL_DEPENDS+=	p5-Test-TCP>=0:../../net/p5-Test-TCP

PERL5_PACKLIST=	auto/PerlIO/via/Timeout/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
