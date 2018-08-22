# $NetBSD: Makefile,v 1.61 2018/08/22 09:43:48 wiz Exp $

DISTNAME=	Curses-1.36
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Curses/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Curses/
COMMENT=	Perl5 module for terminal screen handling and optimization
LICENSE=	gnu-gpl-v1 OR artistic

PERL5_PACKLIST=		auto/Curses/.packlist

MAKE_PARAMS+=	FORMS MENUS

.include "../../lang/perl5/module.mk"
.include "../../mk/curses.buildlink3.mk"

.if ${CURSES_TYPE} == "curses"
# We should really work out the location of the system forms.h
SUBST_CLASSES+=		h_form
SUBST_STAGE.h_form=	post-configure
SUBST_MESSAGE.h_form=	Hard wiring form.h
SUBST_FILES.h_form=	c-config.h
SUBST_SED.h_form=	-e 's,<form.h>,"/usr/include/form.h",g'

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
MAKE_ENV+=	CURSES_LIBTYPE=${CURSES_LIBTYPE}
MAKE_ENV+=	CURSES_CFLAGS=${BUILDLINK_INCDIRS.${CURSES_TYPE}:@dir@-I${dir}@:Q}
MAKE_ENV+=	CURSES_LDFLAGS="-L${BUILDLINK_PREFIX.${CURSES_TYPE}}/lib ${BUILDLINK_LDADD.${CURSES_TYPE}}"
.endif

.include "../../mk/bsd.pkg.mk"
