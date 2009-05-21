# $NetBSD: Makefile,v 1.4 2009/05/21 15:10:04 sno Exp $

DISTNAME=	Data-Compare-1.2101
PKGNAME=	p5-${DISTNAME:S/2101/21.01/}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Data-Compare/
COMMENT=	Perl5 module comparing arbitrary data structures
LICENSE=	gnu-gpl-v2 # OR artistic

DEPENDS+=	p5-File-Find-Rule>=0.10:../../devel/p5-File-Find-Rule

PERL5_PACKLIST=	auto/Data/Compare/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
