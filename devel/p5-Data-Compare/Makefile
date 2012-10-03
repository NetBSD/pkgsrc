# $NetBSD: Makefile,v 1.9 2012/10/03 21:54:49 wiz Exp $

DISTNAME=	Data-Compare-1.22
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Data-Compare/
COMMENT=	Perl5 module comparing arbitrary data structures
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-File-Find-Rule>=0.10:../../devel/p5-File-Find-Rule

PERL5_PACKLIST=		auto/Data/Compare/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
