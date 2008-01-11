# $NetBSD: Makefile,v 1.2 2008/01/11 13:39:43 gdt Exp $

VERSION=	5.0.2
DISTNAME=	gutenprint-${VERSION}
EXTRACT_SUFX=	.tar.bz2
PKGNAME=	gutenprint-lib-${VERSION}
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gimp-print/}

MAINTAINER=	gdt@NetBSD.org
COMMENT=	Drivers for Canon, Epson, Lexmark, and PCL printers
HOMEPAGE=	http://gutenprint.sourceforge.net/

# Not sure if this works.
#PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake lex pkg-config
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES

USE_LANGUAGES+=		c99 c++
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

# Adjust configure to disable components that we don't want.  For
# components that should eventually be in split packages, we mark them
# as such.  Related configure options are grouped together; for now we list
# many default options that probably will not be exercised.

# GTK1 ui and gimp1 plugin.  These are obsolete and will not
# be supported.
CONFIGURE_ARGS+=	--disable-libgutenprintui
CONFIGURE_ARGS+=	--without-gimp

# CUP support.  This should be in a split package
#CONFIGURE_ARGS+=	--without-cups
#CONFIGURE_ARGS+=	--enable-cups-1_2-enhancements
#CONFIGURE_ARGS+=	--disable-cups-ppds
#CONFIGURE_ARGS+=	--disable-translated-cups-ppds

# Ghostscript support.  This should be in split packages, if at all.
CONFIGURE_ARGS+=	--without-ghost

# GTK2 ui and gimp2 plugin
#CONFIGURE_ARGS+=	--disable-libgutenprintui2
#CONFIGURE_ARGS+=	--without-gimp2
# By default, the gimp2 plugin is named gutenprint
#CONFIGURE_ARGS+=	--with-gimp2-as-gutenprint

# Foomatic support.  This should be in a split package, if at all.
CONFIGURE_ARGS+=	--without-foomatic		# split-pkg
#CONFIGURE_ARGS+=	--with-foomatic3		# IN ABOVE

# Disable translated ppds.  Without this option, there are dozens of
# copies of each printer, differing in the CUPS UI only by a language
# code.  The awkwardness seems to outweigh the benefit.
CONFIGURE_ARGS+=	--without-translated-ppds

# Sample images.  These are small so there seems to be no point in
# omitting them.
#CONFIGURE_ARGS+=	--disable-samples		# base

# escputil.  This is a utility for epson printers.  It should arguably
# be in a split package, but it is tiny so there is little point other
# than cleanliness.
#CONFIGURE_ARGS+=	--disable-escputil
# XXX Something in gutenprint seems to use readline, but it's not clear why,
# so just disable it to reduce dependencies.
CONFIGURE_ARGS+=	--without-readline

# test pattern generator.
#CONFIGURE_ARGS+=	--disable-test
#CONFIGURE_ARGS+=	--disable-testpattern

# iconv?

.include "../../devel/gettext-lib/buildlink3.mk"

# gutenprint-gimp: gimp plugin
.include "../../graphics/gimp/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

# gutenprint-cups: cups support
.include "../../print/cups/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
