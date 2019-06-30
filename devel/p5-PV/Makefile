# $NetBSD: Makefile,v 1.36 2019/06/30 20:15:32 nia Exp $

DISTNAME=	PerlVision-1.5
PKGNAME=	p5-PV-1.5
PKGREVISION=	9
CATEGORIES=	devel net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PV/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/PerlVision
COMMENT=	Perl5 library for text-mode user interface widgets

DEPENDS+=	p5-Curses>=1.02:../../devel/p5-Curses

PERL5_PACKLIST=	auto/PV/.packlist

pre-configure:
	${CP} ${FILESDIR}/Makefile.PL ${WRKSRC}/Makefile.PL

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
