# $NetBSD: Makefile,v 1.33 2019/08/11 13:19:36 wiz Exp $

DISTNAME=	IO-All-0.87
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:S/${MODULE_DIR}/${AUTHOR_DIR}/}
MODULE_DIR=	modules/by-module
AUTHOR_DIR=	authors/id/F/FR/FREW

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/IO-All
COMMENT=	Spiffy OO interface to Perl IO
LICENSE=	${PERL5_LICENSE}

USE_TOOLS+=	perl

PERL5_PACKLIST=		auto/IO/All/.packlist

DEPENDS+=	p5-File-MimeInfo-[0-9]*:../../devel/p5-File-MimeInfo
DEPENDS+=	p5-File-ReadBackwards-[0-9]*:../../textproc/p5-File-ReadBackwards

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
