# $NetBSD: Makefile,v 1.18 2006/11/05 04:09:39 obache Exp $
#

DISTNAME=	Net-Daemon-0.39
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5nda
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://search.cpan.org/~jwied/Net-Daemon/
COMMENT=	Perl5 module for writing networking daemons

PERL5_PACKLIST=		auto/Net/Daemon/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
