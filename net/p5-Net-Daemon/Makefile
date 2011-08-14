# $NetBSD: Makefile,v 1.24 2011/08/14 14:14:43 obache Exp $
#

DISTNAME=	Net-Daemon-0.43
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
SVR4_PKGNAME=	p5nda
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-Daemon/
COMMENT=	Perl5 module for writing networking daemons

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/Net-Daemon/

PERL5_PACKLIST=		auto/Net/Daemon/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
