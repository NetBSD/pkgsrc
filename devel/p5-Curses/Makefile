# $NetBSD: Makefile,v 1.43 2013/10/16 16:27:26 roy Exp $

DISTNAME=	Curses-1.28
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
SVR4_PKGNAME=	p5cur
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Curses/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Curses/
COMMENT=	Perl5 module for terminal screen handling and optimization
# really it's gnu-gpl-v1+ OR artistic-1.0, but currently we don't have gplv1
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Curses/.packlist

# We should really work out the location of the system forms.h
SUBST_STAGE.h_form	= post-configure
SUBST_MESSAGE.h_form	= Hard wiring form.h
SUBST_FILES.h_form	= c-config.h
SUBST_SED.h_form	= -e 's,<form.h>,"/usr/include/form.h",g'

MAKE_PARAMS+=	FORMS MENUS

.include "../../lang/perl5/module.mk"
.include "../../mk/curses.buildlink3.mk"

.if ${CURSES_TYPE} == "curses"
SUBST_CLASSES+=		h_form
.elif ${CURSES_TYPE} == "ncurses" || ${CURSES_TYPE} == "ncursesw"
MAKE_PARAMS+=		PANELS
# Don't link to system termcap as we're using ncurses
BUILDLINK_TRANSFORM+=	rm:-ltermcap

# Use the FreeBSD ncurses config as that works fine for pkgsrc
pre-configure:
	${LN} -sf ${WRKSRC}/hints/c-freebsd.ncurses.h ${WRKSRC}/c-config.h
.endif

.include "../../mk/bsd.pkg.mk"
