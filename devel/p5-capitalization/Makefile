# $NetBSD: Makefile,v 1.6 2010/08/21 16:34:45 seb Exp $

DISTNAME=	capitalization-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MI/MIYAGAWA/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/capitalization/
COMMENT=	Perl module for no capitalization on method names

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Devel-Symdump-[0-9]*:../../devel/p5-Devel-Symdump

PERL5_PACKLIST=		auto/capitalization/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
