# $NetBSD: Makefile,v 1.1.1.1 2008/12/17 00:44:06 he Exp $
#

DISTNAME=	Rose-DBx-AutoReconnect-0.02
SVR4_PKGNAME=	p5rda
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Rose/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Rose-DBx-AutoReconnect/
COMMENT=	Perl5 module for Rose::DB with auto-reconnect to server

DEPENDS+=	p5-Rose-DB>=0.743:../../databases/p5-Rose-DB

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Rose/DBx/AutoReconnect/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
