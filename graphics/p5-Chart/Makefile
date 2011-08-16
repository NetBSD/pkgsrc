# $NetBSD: Makefile,v 1.12 2011/08/16 21:53:41 wiz Exp $

DISTNAME=	Chart-2.4.2
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Chart/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~chartgrp/
COMMENT=	Perl5 charting library
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-GD>=1.20:../../graphics/p5-GD

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/Chart/.packlist

post-extract:
	${CHMOD} a-x ${WRKSRC}/Chart/*.pm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
