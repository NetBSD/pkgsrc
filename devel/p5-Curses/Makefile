# $NetBSD: Makefile,v 1.54 2016/06/08 19:22:44 wiz Exp $

DISTNAME=	Curses-1.34
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Curses/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Curses/
COMMENT=	Perl5 module for terminal screen handling and optimization
# really it's gnu-gpl-v1+ OR artistic-1.0, but currently we don't have gplv1
LICENSE=	${PERL5_LICENSE}

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

# Pass appropriate CURSES_LIBTYPE so Curses will link to the matching panel/menu/form library
.if ${CURSES_TYPE} == "curses"
.  if ${OPSYS} == "Linux"
CURSES_LIBTYPE=		ncurses
.  else
CURSES_LIBTYPE=		bsd
.  endif
.elif ${CURSES_TYPE} == "ncurses"
CURSES_LIBTYPE=		ncurses
.elif ${CURSES_TYPE} == "ncursesw"
CURSES_LIBTYPE=		ncursesw
.endif

.if defined(CURSES_LIBTYPE)
MAKE_ENV+=		CURSES_LIBTYPE=${CURSES_LIBTYPE}
MAKE_ENV+=		CURSES_CFLAGS=${BUILDLINK_INCDIRS.${CURSES_TYPE}:S/^/-I/}
MAKE_ENV+=		CURSES_LDFLAGS=${BUILDLINK_LDADD.${CURSES_TYPE}}
.endif

.include "../../mk/bsd.pkg.mk"
