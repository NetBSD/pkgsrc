# $NetBSD: Makefile,v 1.40 2015/01/18 06:18:58 mef Exp $

DISTNAME=		avrdude-6.1
PKGREVISION=		1
CATEGORIES=		cross
MASTER_SITES=		http://download.savannah.gnu.org/releases/avrdude/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.nongnu.org/avrdude/
COMMENT=		Downloader/uploader for Atmel AVR 8-bit RISC microcontrollers
LICENSE=		gnu-gpl-v2

BUILD_DEPENDS+=		dvipsk-[0-9]*:../../print/dvipsk
BUILD_DEPENDS+=		tex-latex-fonts-[0-9]*:../../fonts/tex-latex-fonts
BUILD_DEPENDS+=		tex-pdftex-[0-9]*:../../print/tex-pdftex

# make: make: don't know how to make ./libavrdude.a. Stop
MAKE_JOBS_SAFE=		no

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=		yes
TEXINFO_REQD=		4.9
USE_TOOLS+=		autoconf automake autoreconf makeinfo texi2html yacc lex
INFO_FILES=		yes
EGDIR=			${PREFIX}/share/examples/avrdude
CONF_FILES_PERMS=	${EGDIR}/avrdude.conf ${PKG_SYSCONFDIR}/avrdude.conf \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 644

CONFIGURE_ARGS+=	--enable-doc
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ENV+=		DEFAULT_SER_PORT=${DEFAULT_SERIAL_DEVICE:Q}
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
.include "../../devel/libusb/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
# elf_getshdrstrndx
.include "../../devel/libelf/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
