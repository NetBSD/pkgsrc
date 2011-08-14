# $NetBSD: Makefile,v 1.15 2011/08/14 12:26:09 obache Exp $

DISTNAME=	IO-All-0.41
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:S/${MODULE_DIR}/${AUTHOR_DIR}/}
MODULE_DIR=	modules/by-module
AUTHOR_DIR=	authors/id/I/IN/INGY

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/IO-All/
COMMENT=	Spiffy OO interface to Perl IO

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	perl

PERL5_PACKLIST=		auto/IO/All/.packlist

DEPENDS+=	p5-IO-String-[0-9]*:../../devel/p5-IO-String

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
