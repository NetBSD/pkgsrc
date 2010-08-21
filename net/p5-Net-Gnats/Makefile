# $NetBSD: Makefile,v 1.11 2010/08/21 16:35:24 seb Exp $
#

DISTNAME=	Net-Gnats-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnatsperl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gnatsperl.sourceforge.net/
#HOMEPAGE=	http://search.cpan.org/dist/Net-Gnats/
COMMENT=	Perl interface to the gnatsd daemon

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Net/Gnats/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
