# $NetBSD: Makefile,v 1.16 2005/03/24 21:12:53 wiz Exp $

DISTNAME=	PerlVision-1.4
PKGNAME=	p5-PV-1.4
SVR4_PKGNAME=	p5pvi
PKGREVISION=	1
CATEGORIES=	devel net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PV/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 library for text-mode user interface widgets

DEPENDS+=	p5-Curses>=1.02:../../devel/p5-Curses

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/PV/.packlist

pre-configure:
	@${CP} ${FILESDIR}/Makefile.PL ${WRKSRC}/Makefile.PL

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
