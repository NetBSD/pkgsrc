# $NetBSD: Makefile,v 1.20 2022/06/28 11:31:29 wiz Exp $
#

DISTNAME=	Rose-DBx-AutoReconnect-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Rose/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Rose-DBx-AutoReconnect
COMMENT=	Perl5 module for Rose::DB with auto-reconnect to server
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Rose-DB>=0.743:../../databases/p5-Rose-DB

PERL5_PACKLIST=	auto/Rose/DBx/AutoReconnect/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
