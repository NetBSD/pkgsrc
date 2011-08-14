# $NetBSD: Makefile,v 1.4 2011/08/14 14:52:49 obache Exp $
#

DISTNAME=	File-chmod-0.32
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	perl5 sysutils
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/P/PI/PINYAN/
COMMENT=	Perl API-Implements symbolic and ls chmod modes

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/File/chmod/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
