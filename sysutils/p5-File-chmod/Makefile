# $NetBSD: Makefile,v 1.1 2007/12/11 12:19:18 rhaen Exp $
#

DISTNAME=	File-chmod-0.32
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 sysutils
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/P/PI/PINYAN/
COMMENT=	Perl API-Implements symbolic and ls chmod modes

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/File/chmod/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
