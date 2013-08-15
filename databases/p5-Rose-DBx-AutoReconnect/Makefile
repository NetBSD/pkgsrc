# $NetBSD: Makefile,v 1.9 2013/08/15 12:33:00 wen Exp $
#

DISTNAME=	Rose-DBx-AutoReconnect-0.04
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5rda
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Rose/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Rose-DBx-AutoReconnect/
COMMENT=	Perl5 module for Rose::DB with auto-reconnect to server
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Rose-DB>=0.743:../../databases/p5-Rose-DB

PERL5_PACKLIST=	auto/Rose/DBx/AutoReconnect/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
