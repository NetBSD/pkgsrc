# $NetBSD: Makefile,v 1.4 2011/08/13 07:46:03 adam Exp $

DISTNAME=	File-Find-Rule-PPI-1.06
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Find-Rule-PPI/
COMMENT=	Add support for PPI queries to File::Find::Rule
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-File-Find-Rule>=0.20:../../devel/p5-File-Find-Rule
DEPENDS+=	p5-PPI>=1.00:../../devel/p5-PPI
DEPENDS+=	p5-Params-Util>=0.10:../../devel/p5-Params-Util

PERL5_PACKLIST=		auto/File/Find/Rule/PPI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
