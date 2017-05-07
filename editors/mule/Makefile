# $NetBSD: Makefile,v 1.54 2017/05/07 06:49:23 tsutsui Exp $

DISTNAME=	mule-2.3
PKGREVISION=	9
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.m17n.org/pub/mule/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.m17n.org/mule/
COMMENT=	Multilingual GNU editing macros (editor)
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=		no

CONFLICTS=	emacs-[0-9]*

# build PATH in the dumped mule is not a problem
CHECK_WRKREF_SKIP+=	bin/mule
CHECK_WRKREF_SKIP+=	bin/mule-19.28

WRKSRC=			${WRKDIR}/mule
USE_TOOLS+=		gmake makeinfo
GNU_CONFIGURE=		yes
GNU_CONFIGURE_MANDIR=	${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

CFLAGS+=	-g -fno-builtin-malloc -fno-strict-aliasing

CONFIGURE_ARGS+=	${MACHINE_ARCH}--${LOWER_OPSYS} --with-x --with-x-toolkit=lucid
CONFIGURE_ARGS+=	--terminal-face --mcpath --canna-libraries=${PREFIX}/lib
.if ${MACHINE_ARCH} != "alpha" && ${MACHINE_ARCH} != "sparc64"
CONFIGURE_ARGS+=	--valbits=26
.endif
CONFIGURE_ARGS+=	--bdf-path=${PREFIX}/share/fonts/X11/intlfonts/bdf

.include "options.mk"

INFO_FILES=	yes

INSTALL_MAKE_FLAGS=	prefix=${DESTDIR}${PREFIX}
INSTALL_MAKE_FLAGS+=	infodir=${DESTDIR}${GNU_CONFIGURE_INFODIR}
INSTALL_MAKE_FLAGS+=	mandir=${DESTDIR}${GNU_CONFIGURE_MANDIR}

# Remove .orig files in the original tar archive
post-extract:
	rm -f ${WRKSRC}/lisp/*.orig

# Remove original versions of patched files so that aren't installed.
post-build:
	${FIND} ${WRKSRC} -name "*.orig" | ${XARGS} ${RM} -f

# Fix character mapping for pkgsrc/fonts/intlfonts
post-install:
	${SED} \
		-e 's/etl\([0-9]*\)-latin1/lt1-40-etl/' \
		-e 's/etl\([0-9]*\)-latin\([0-9]\)/lt\2-\1-etl/' \
		-e 's/jiskan24/j83-48/' \
		< ${WRKSRC}/etc/CHARSETS > ${DESTDIR}${PREFIX}/lib/mule/19.28/etc/CHARSETS
	#diff -u		${WRKSRC}/etc/CHARSETS ${DESTDIR}${PREFIX}/lib/mule/19.28/etc/CHARSETS

.include "../../x11/xbitmaps/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
