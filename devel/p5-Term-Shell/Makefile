# $NetBSD: Makefile,v 1.3 2012/10/03 21:55:39 wiz Exp $
#

DISTNAME=	Term-Shell-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/N/NE/NEILW/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~neilw/${DISTNAME}/
COMMENT=	Write command-line shells in Perl

DEPENDS+=	p5-Term-ReadKey>=2.30:../../devel/p5-Term-ReadKey

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Term/Shell/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
