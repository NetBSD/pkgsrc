# $NetBSD: Makefile,v 1.6 2018/08/22 09:43:36 wiz Exp $

GIT_COMMIT=	f5f4dbf

DISTNAME=	motemen-App-Prove-Plugin-ProgressBar-Each-g${GIT_COMMIT}
PKGNAME=	p5-App-Prove-Plugin-ProgressBar-Each-0.01
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	-https://codeload.github.com/motemen/App-Prove-Plugin-ProgressBar-Each/tar.gz/${GIT_COMMIT}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://github.com/motemen/App-Prove-Plugin-ProgressBar-Each/
COMMENT=	Per-test-script progress bar for Perl prove(1)
#LICENSE=	${PERL5_LICENSE}

WRKSRC=		${WRKDIR}/App-Prove-Plugin-ProgressBar-Each-${GIT_COMMIT}

DEPENDS+=	p5-Term-ProgressBar-Simple-[0-9]*:../../devel/p5-Term-ProgressBar-Simple

USE_LANGUAGES=	# empty
USE_TOOLS+=	perl
PERL5_PACKLIST=	auto/App/Prove/Plugin/ProgressBar/Each/.packlist
PERL5_MODULE_TYPE=Module::Install

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
