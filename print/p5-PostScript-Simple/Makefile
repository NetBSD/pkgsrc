# $NetBSD: Makefile,v 1.1.1.1 2009/05/01 21:57:17 sno Exp $

DISTNAME=	PostScript-Simple-0.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	print perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PostScript/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/PostScript-Simple/
COMMENT=	Produce PostScript files from Perl
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/PostScript/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
