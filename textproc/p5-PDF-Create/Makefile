# $NetBSD: Makefile,v 1.58 2023/07/06 09:41:42 wiz Exp $

DISTNAME=	PDF-Create-1.46
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PDF/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/PDF-Create
COMMENT=	Perl5 module for creating pdf documents
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/PDF/Create/.packlist

DEPENDS+=	p5-File-Share>=0.25:../../devel/p5-File-Share
DEPENDS+=	p5-File-ShareDir>=0:../../devel/p5-File-ShareDir
DEPENDS+=	p5-File-ShareDir-Install>=0:../../devel/p5-File-ShareDir-Install
DEPENDS+=	p5-JSON>=0:../../converters/p5-JSON
DEPENDS+=	p5-Class-Inspector>=0:../../devel/p5-Class-Inspector

TOOL_DEPENDS=	p5-Test-LeakTrace>=0.14:../../devel/p5-Test-LeakTrace
TOOL_DEPENDS+=	p5-Test-CheckManifest>=0.9:../../devel/p5-Test-CheckManifest

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
