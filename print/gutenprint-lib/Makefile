# $NetBSD: Makefile,v 1.24 2011/01/13 13:39:12 wiz Exp $

VERSION=	5.2.6
DISTNAME=	gutenprint-${VERSION}
PKGNAME=	gutenprint-lib-${VERSION}
PKGREVISION=	3
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gimp-print/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	gdt@NetBSD.org
COMMENT=	Drivers for Canon, Epson, Lexmark, and PCL printers
HOMEPAGE=	http://gutenprint.sourceforge.net/

PREV_PKGPATH=	print/gutenprint51-lib

INSTALLVERSION=	5.2
PLIST_SUBST+=	INSTALLVERSION=${INSTALLVERSION}
PRINT_PLIST_AWK+=	{ gsub("gutenprint/${INSTALLVERSION}", \
				"gutenprint/$${INSTALLVERSION}") }
PRINT_PLIST_AWK+=	{ gsub(".${INSTALLVERSION}$$", \
				".$${INSTALLVERSION}") }

PKG_DESTDIR_SUPPORT=	user-destdir

# Not sure if this works.
#PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake lex pkg-config perl:run
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES

USE_LANGUAGES+=		c99
# gcc 3.3.3 either can't compile this, or needs huge amounts of RAM (0.5G+).
# Observed on NetBSD/i386 3 and confirmed with upstream.  Apparently it's
# just 3.3.3 - there are no known issues with 2.95.

# gutenprint has many options, and really should be split into
# multiple packages.  Splitting is difficult because of the structure
# of the upstream distribution.  For now, this package contains
# everything that gdt wants, because that seems more useful to users
# than not having gutenprint in pkgsrc.

GNU_CONFIGURE=		YES

# XXX Make command.types be a CONF_FILE

# Adjust configure to disable components that we don't want.  Note
# components that should eventually be in split packages.

# GTK1 ui and gimp1 plugin.  These are obsolete and will not
# be supported.
CONFIGURE_ARGS+=	--disable-libgutenprintui
CONFIGURE_ARGS+=	--without-gimp

# CUPS support, on by default.  This should be in a split package.
#CONFIGURE_ARGS+=	--with-cups
#CONFIGURE_ARGS+=	--enable-cups-1_2-enhancements
#CONFIGURE_ARGS+=	--enable-cups-ppds
# TODO: check status of translated cups ppds
#CONFIGURE_ARGS+=	--disable-translated-cups-ppds

# Ghostscript support.  This should be in a split package, if at all.
CONFIGURE_ARGS+=	--without-ghost

# GTK2 ui, and gimp plugin
#CONFIGURE_ARGS+=	--enable-libgutenprintui2
#CONFIGURE_ARGS+=	--with-gimp2
# By default, the gimp2 plugin is named gutenprint
#CONFIGURE_ARGS+=	--with-gimp2-as-gutenprint

# Foomatic support.  This should be in a split package, if at all.
CONFIGURE_ARGS+=	--without-foomatic
#CONFIGURE_ARGS+=	--with-foomatic3

# Disable translated ppds.  Without this option, there are dozens of
# copies of each printer, differing in the CUPS UI only by a language
# code.  The awkwardness seems to outweigh the benefit.
CONFIGURE_ARGS+=	--without-translated-ppds

# Sample images are small so there seems to be no point in omitting
# them.
#CONFIGURE_ARGS+=	--enable-samples

# escputil is a utility for Epson printers.  It should arguably be in
# a split package, but it is so small that there is no point, and it's
# very useful.
#CONFIGURE_ARGS+=	--enable-escputil

# Something in gutenprint seems to use readline, but it's not clear
# why, so just disable it to reduce dependencies.
CONFIGURE_ARGS+=	--without-readline

# test pattern generator.
#CONFIGURE_ARGS+=	--disable-test
#CONFIGURE_ARGS+=	--disable-testpattern

TEST_TARGET=		check

# A libintl is optional in gutenprint.
.include "../../devel/gettext-lib/buildlink3.mk"

# gutenprint-gimp: gimp plugin
.include "../../graphics/gimp/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

# gutenprint-cups: cups support
.include "../../print/cups/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
