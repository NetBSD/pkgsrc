# $NetBSD: Makefile,v 1.19 2005/08/06 06:19:13 jlam Exp $

DISTNAME=	PerlVision-1.4
PKGNAME=	p5-PV-1.4
SVR4_PKGNAME=	p5pvi
PKGREVISION=	2
CATEGORIES=	devel net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PV/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 library for text-mode user interface widgets

DEPENDS+=	p5-Curses>=1.02:../../devel/p5-Curses

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/PV/.packlist

pre-configure:
	@${CP} ${FILESDIR}/Makefile.PL ${WRKSRC}/Makefile.PL

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
