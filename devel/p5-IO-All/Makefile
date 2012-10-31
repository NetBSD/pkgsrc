# $NetBSD: Makefile,v 1.20 2012/10/31 11:18:19 asau Exp $

DISTNAME=	IO-All-0.44
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:S/${MODULE_DIR}/${AUTHOR_DIR}/}
MODULE_DIR=	modules/by-module
AUTHOR_DIR=	authors/id/I/IN/INGY

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/IO-All/
COMMENT=	Spiffy OO interface to Perl IO
LICENSE=	${PERL5_LICENSE}

USE_TOOLS+=	perl

PERL5_PACKLIST=		auto/IO/All/.packlist

DEPENDS+=	p5-IO-String-[0-9]*:../../devel/p5-IO-String

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
