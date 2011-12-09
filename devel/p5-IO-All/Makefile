# $NetBSD: Makefile,v 1.18 2011/12/09 06:59:50 hiramatsu Exp $

DISTNAME=	IO-All-0.44
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:S/${MODULE_DIR}/${AUTHOR_DIR}/}
MODULE_DIR=	modules/by-module
AUTHOR_DIR=	authors/id/I/IN/INGY

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/IO-All/
COMMENT=	Spiffy OO interface to Perl IO
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	perl

PERL5_PACKLIST=		auto/IO/All/.packlist

DEPENDS+=	p5-IO-String-[0-9]*:../../devel/p5-IO-String

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
