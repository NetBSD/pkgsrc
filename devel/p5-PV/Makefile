# $NetBSD: Makefile,v 1.25 2011/08/14 12:26:27 obache Exp $

DISTNAME=	PerlVision-1.5
PKGNAME=	p5-PV-1.5
PKGREVISION=	2
SVR4_PKGNAME=	p5pvi
CATEGORIES=	devel net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PV/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/PerlVision/
COMMENT=	Perl5 library for text-mode user interface widgets

DEPENDS+=	p5-Curses>=1.02:../../devel/p5-Curses

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/PV/.packlist

pre-configure:
	${CP} ${FILESDIR}/Makefile.PL ${WRKSRC}/Makefile.PL

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
