# $NetBSD: Makefile,v 1.1.1.1 2006/07/29 00:38:19 minskim Exp $
#

DISTNAME=	Proc-Simple-1.21
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Proc/}

MAINTAINER=	dhowland@users.sourceforge.net
HOMEPAGE=	http://www.cpan.org/
COMMENT=	Launch and control background processes

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Proc/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
