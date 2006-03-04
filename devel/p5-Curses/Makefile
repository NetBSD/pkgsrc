# $NetBSD: Makefile,v 1.30 2006/03/04 21:29:20 jlam Exp $

DISTNAME=	Curses-1.12
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5cur
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Curses/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Curses/
COMMENT=	Perl5 module for terminal screen handling and optimization

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_NCURSES=	# needs libpanel

WRKSRC=		${WRKDIR}/Curses-1.12
PERL5_PACKLIST=		auto/Curses/.packlist

MAKE_PARAMS+=	PANELS
# does not compile on 2.0 because of conflicts between perl internal header
# files and stdbool.h
#MAKE_PARAMS+=	FORMS MENUS

pre-configure:
	@${LN} -sf ${WRKSRC}/hints/c-netbsd.ncurses.h ${WRKSRC}/c-config.h

.include "../../devel/ncurses/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
