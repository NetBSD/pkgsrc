# $NetBSD: Makefile,v 1.39 2006/12/06 16:42:20 joerg Exp $

DISTNAME=	mule-2.3
PKGREVISION=	4
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.m17n.org/pub/mule/

MAINTAINER=	kei@NetBSD.org
HOMEPAGE=	http://www.m17n.org/mule/MulePage.en.html
COMMENT=	Multilingual GNU editing macros (editor)

CONFLICTS=	emacs-[0-9]*

# build PATH in the dumped mule is not a problem
CHECK_WRKREF_SKIP+=	bin/mule
CHECK_WRKREF_SKIP+=	bin/mule-19.28

WRKSRC=			${WRKDIR}/mule
USE_TOOLS+=		gmake makeinfo
GNU_CONFIGURE=		yes
GNU_CONFIGURE_MANDIR=	${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

CFLAGS+=	-g

CONFIGURE_ARGS+=	${MACHINE_ARCH}--${LOWER_OPSYS} --with-x --with-x-toolkit=lucid
CONFIGURE_ARGS+=	--terminal-face --mcpath --canna-libraries=${PREFIX}/lib
.if ${MACHINE_ARCH} != "alpha" && ${MACHINE_ARCH} != "sparc64"
CONFIGURE_ARGS+=	--valbits=26
.endif
CONFIGURE_ARGS+=	--bdf-path=${X11PREFIX}/lib/X11/fonts/intlfonts/bdf

.include "options.mk"

INFO_FILES=	# PLIST

.include "../../mk/x11.buildlink3.mk"

# Remove original versions of patched files so that aren't installed.
post-build:
	${FIND} ${WRKSRC} -name "*.orig" | ${XARGS} ${RM} -f

# Fix character mapping for pkgsrc/fonts/intlfonts
post-install:
	${SED} \
		-e 's/etl\([0-9]*\)-latin1/lt1-40-etl/' \
		-e 's/etl\([0-9]*\)-latin\([0-9]\)/lt\2-\1-etl/' \
		-e 's/jiskan24/j83-48/' \
		< ${WRKSRC}/etc/CHARSETS > ${PREFIX}/lib/mule/19.28/etc/CHARSETS
	#diff -u		${WRKSRC}/etc/CHARSETS ${PREFIX}/lib/mule/19.28/etc/CHARSETS

.include "../../mk/bsd.pkg.mk"
