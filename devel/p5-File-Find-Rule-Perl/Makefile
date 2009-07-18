# $NetBSD: Makefile,v 1.2 2009/07/18 17:50:56 sno Exp $

DISTNAME=	File-Find-Rule-Perl-1.08
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Find-Rule-Perl/
COMMENT=	Common File::Find::Rule rules for searching for Perl things
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-File-Find-Rule>=0.20:../../devel/p5-File-Find-Rule
DEPENDS+=	p5-Params-Util>=0.38:../../devel/p5-Params-Util
DEPENDS+=	p5-Parse-CPAN-Meta>=0.04:../../devel/p5-Parse-CPAN-Meta

PERL5_PACKLIST=		auto/File/Find/Rule/Perl/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
