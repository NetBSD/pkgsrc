# $NetBSD: Makefile,v 1.2 2008/06/12 02:14:25 joerg Exp $
#

DISTNAME=	Proc-Simple-1.21
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Proc/}

MAINTAINER=	dhowland@users.sourceforge.net
HOMEPAGE=	http://www.cpan.org/
COMMENT=	Launch and control background processes

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Proc/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
