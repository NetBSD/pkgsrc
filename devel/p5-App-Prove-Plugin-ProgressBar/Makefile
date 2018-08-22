# $NetBSD: Makefile,v 1.8 2018/08/22 09:43:36 wiz Exp $

GIT_COMMIT=	dd51ac5

DISTNAME=	${GIT_COMMIT}
PKGNAME=	p5-App-Prove-Plugin-ProgressBar-0.01
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	-http://nodeload.github.com/Ovid/App-Prove-Plugin-ProgressBar/tar.gz/${GIT_COMMIT}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://github.com/Ovid/App-Prove-Plugin-ProgressBar/
COMMENT=	Progress bar for Perl prove(1)
LICENSE=	${PERL5_LICENSE}

WRKSRC=		${WRKDIR}/App-Prove-Plugin-ProgressBar-${GIT_COMMIT}

DEPENDS+=	p5-Modern-Perl-[0-9]*:../../devel/p5-Modern-Perl
DEPENDS+=	p5-Term-ProgressBar>=2.09:../../devel/p5-Term-ProgressBar

USE_LANGUAGES=	# empty
USE_TOOLS+=	perl
PERL5_PACKLIST=	auto/App/Prove/Plugin/ProgressBar/.packlist
PERL5_MODULE_TYPE=Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
