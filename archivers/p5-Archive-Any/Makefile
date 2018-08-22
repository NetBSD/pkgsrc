# $NetBSD: Makefile,v 1.19 2018/08/22 09:42:53 wiz Exp $

DISTNAME=	Archive-Any-0.0945
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	archivers perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Archive/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Archive-Any/
COMMENT=	Perl5 module with single interface to deal with archives
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	{perl>=5.9.3,p5-Archive-Tar>=0.22}:../../archivers/p5-Archive-Tar
DEPENDS+=	p5-Archive-Tar>=0:../../archivers/p5-Archive-Tar
DEPENDS+=	p5-Archive-Zip>=0:../../archivers/p5-Archive-Zip
DEPENDS+=	p5-File-MMagic>=0:../../misc/p5-File-MMagic
DEPENDS+=	p5-MIME-Types>=0:../../mail/p5-MIME-Types
DEPENDS+=	p5-Module-Find>=0:../../devel/p5-Module-Find

BUILD_DEPENDS+=	p5-Test-Warn>0:../../devel/p5-Test-Warn

PERL5_PACKLIST=		auto/Archive/Any/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
