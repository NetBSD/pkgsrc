# $NetBSD: Makefile,v 1.46 2019/06/08 10:53:27 rillig Exp $

DISTNAME=		avrdude-6.3
PKGREVISION=		2
CATEGORIES=		cross
MASTER_SITES=		http://download.savannah.gnu.org/releases/avrdude/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.nongnu.org/avrdude/
COMMENT=		Downloader/uploader for Atmel AVR 8-bit RISC microcontrollers
LICENSE=		gnu-gpl-v2

BUILD_DEPENDS+=		dvipsk-[0-9]*:../../print/dvipsk
BUILD_DEPENDS+=		tex-latex-fonts-[0-9]*:../../fonts/tex-latex-fonts
BUILD_DEPENDS+=		tex-pdftex-[0-9]*:../../print/tex-pdftex

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=		yes
TEXINFO_REQD=		4.9
USE_TOOLS+=		autoconf automake autoreconf lex makeinfo texi2html yacc
# Upstream does not documentat that GNU make is required, but BSD make
# leads to inexplicable errors about libavrdude.
# \todo Resolve and/or discuss with upstream.
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
INFO_FILES=		yes
EGDIR=			${PREFIX}/share/examples/avrdude
CONF_FILES_PERMS=	${EGDIR}/avrdude.conf ${PKG_SYSCONFDIR}/avrdude.conf \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 644

CONFIGURE_ARGS+=	--enable-doc
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ENV+=		DEFAULT_SER_PORT=${DEFAULT_SERIAL_DEVICE}
PLIST_SUBST+=		DISTNAME=${DISTNAME}

# The autotools used by this pkg are older than what's in pkgsrc
# currently.  This makes the diffs huge.
pre-configure:
	cd ${WRKSRC} && autoreconf -vif

# DragonFly has stripped makeinfo in the base - without texi2dvi.
.if ${OPSYS} == "DragonFly"
BUILD_DEPENDS+=		gtexinfo-[0-9]*:../../devel/gtexinfo
.endif

.include "../../devel/libftdi/buildlink3.mk"
.include "../../devel/libhid/buildlink3.mk"
.include "../../devel/libftdi1/buildlink3.mk"
.include "../../mk/libusb.buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
# elf_getshdrstrndx
.include "../../devel/libelf/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
