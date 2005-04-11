# $NetBSD: Makefile,v 1.26 2005/04/11 21:45:30 tv Exp $

DISTNAME=	Curses-1.08b
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5cur
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Curses/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Curses/
COMMENT=	Perl5 module for terminal screen handling and optimization

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_NCURSES=	# needs libpanel

WRKSRC=		${WRKDIR}/Curses-1.08
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Curses/.packlist

MAKE_PARAMS+=	PANELS
# does not compile on 2.0 because of conflicts between perl internal header
# files and stdbool.h
#MAKE_PARAMS+=	FORMS MENUS

pre-configure:
	@${LN} -sf ${WRKSRC}/hints/c-netbsd.ncurses.h ${WRKSRC}/c-config.h

.include "../../devel/ncurses/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
