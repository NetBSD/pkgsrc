# $NetBSD: Makefile,v 1.7 2022/06/28 11:33:08 wiz Exp $

DISTNAME=	RT-Extension-ArticleTemplates-1.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/B/BP/BPS/}

MAINTAINER=	spz@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/RT::Extension::ArticleTemplates
COMMENT=	Perl extension for RT
LICENSE=	gnu-gpl-v2

PERL5_MODULE_TYPE=	Module::Install

BUILD_DEPENDS+=	p5-Module-Install-RTx>=0.40:../../devel/p5-Module-Install-RTx
BUILD_DEPENDS+=	p5-Module-Install-ReadmeFromPod>=0.30:../../devel/p5-Module-Install-ReadmeFromPod

USE_TOOLS=	perl

MAKE_ENV+=	RTHOME="${PREFIX}/share/rt4/"
MAKE_ENV+=	INSTALLDIRS="vendor"
MAKE_ENV+=	DESTDIR=${DESTDIR}

DEPENDS+=	rt4-[0-9]*:../../devel/rt4
DEPENDS+=	p5-IO-All-[0-9]*:../../devel/p5-IO-All

.include "../../devel/rt4/dirs.mk"

PERL5_API=	${PERL5_API_cmd:sh}
PERL5_API_cmd=	${TOOLS_CMD.perl} -e 'use Config; print $$Config{api_versionstring};'

PERL5_ARCH=	${PERL5_ARCH_cmd:sh}
PERL5_ARCH_cmd=	${TOOLS_CMD.perl} -e 'use Config; print $$Config{archname};'

PERL5_PACKLIST_DIR=	${PREFIX}/share/rt4/plugins/RT-Extension-ArticleTemplates
PERL5_PACKLIST=		auto/RT/Extension/ArticleTemplates/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
