# $NetBSD: Makefile,v 1.37 2013/11/20 06:11:34 dsainty Exp $

DISTNAME=		avrdude-5.11
PKGREVISION=		1
CATEGORIES=		cross
MASTER_SITES=		http://download.savannah.gnu.org/releases/avrdude/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.nongnu.org/avrdude/
COMMENT=		Downloader/uploader for Atmel AVR 8-bit RISC microcontrollers
LICENSE=		gnu-gpl-v2

BUILD_DEPENDS+=	dvipsk-[0-9]*:../../print/dvipsk
BUILD_DEPENDS+=	tex-latex-fonts-[0-9]*:../../fonts/tex-latex-fonts
BUILD_DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex

MAKE_JOBS_SAFE=		no

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=		yes
TEXINFO_REQD=		4.9
USE_TOOLS+=		autoconf automake autoreconf makeinfo texi2html yacc lex
INFO_FILES=		yes
EGDIR=			${PREFIX}/share/examples/avrdude
CONF_FILES=		${EGDIR}/avrdude.conf ${PKG_SYSCONFDIR}/avrdude.conf

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
.include "../../devel/libusb/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
