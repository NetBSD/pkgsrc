# $NetBSD: Makefile,v 1.26 2012/10/03 21:57:01 wiz Exp $
#

DISTNAME=	Net-Daemon-0.48
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5nda
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-Daemon/
COMMENT=	Perl5 module for writing networking daemons
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

#WRKSRC=		${WRKDIR}/Net-Daemon/

PERL5_PACKLIST=		auto/Net/Daemon/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
