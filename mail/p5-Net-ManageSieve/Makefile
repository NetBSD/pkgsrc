# $NetBSD: Makefile,v 1.4 2010/09/21 21:39:38 sno Exp $

DISTNAME=	Net-ManageSieve-0.10
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-ManageSieve/
COMMENT=	ManageSieve Protocol Client
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Net/ManageSieve/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
