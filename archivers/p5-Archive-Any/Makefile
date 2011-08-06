# $NetBSD: Makefile,v 1.3 2011/08/06 12:18:45 adam Exp $

DISTNAME=	Archive-Any-0.0932
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5aan
CATEGORIES=	archivers perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Archive/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Archive-Any/
COMMENT=	Perl5 module with single interface to deal with archives

DEPENDS+=		p5-Archive-Tar>=0.22:../../archivers/p5-Archive-Tar
DEPENDS+=		p5-Archive-Zip>=1.07:../../archivers/p5-Archive-Zip
DEPENDS+=		p5-File-MMagic>=1.27:../../misc/p5-File-MMagic
DEPENDS+=		p5-MIME-Types>=1.16:../../mail/p5-MIME-Types
DEPENDS+=		p5-Module-Find>=0.05:../../devel/p5-Module-Find
DEPENDS+=		p5-Test-Warn>0:../../devel/p5-Test-Warn

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Archive/Any/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
