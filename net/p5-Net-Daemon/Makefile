# $NetBSD: Makefile,v 1.19 2008/06/12 02:14:39 joerg Exp $
#

DISTNAME=	Net-Daemon-0.39
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5nda
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://search.cpan.org/~jwied/Net-Daemon/
COMMENT=	Perl5 module for writing networking daemons

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Net/Daemon/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
