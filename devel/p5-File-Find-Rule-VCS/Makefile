# $NetBSD: Makefile,v 1.16 2018/08/22 09:44:01 wiz Exp $

DISTNAME=	File-Find-Rule-VCS-1.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Find-Rule-VCS/
COMMENT=	File::Find::Rule extension to Exclude files/directories for VCS's
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-File-Find-Rule>=0.20:../../devel/p5-File-Find-Rule
DEPENDS+=	p5-Text-Glob>=0.08:../../textproc/p5-Text-Glob

PERL5_MODULE_TYPE=	Module::Install::Bundled
PERL5_PACKLIST=		auto/File/Find/Rule/VCS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
