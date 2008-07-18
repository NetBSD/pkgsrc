# $NetBSD: Makefile,v 1.9 2008/07/18 12:55:11 rhaen Exp $

DISTNAME=	Module-Versions-Report-1.05
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Extension to report versions of all modules in memory

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Module-Versions-Report/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
