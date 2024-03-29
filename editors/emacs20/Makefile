# $NetBSD: Makefile,v 1.66 2023/09/25 20:08:32 gdt Exp $

DISTNAME=	emacs-20.7
PKGNAME=	${DISTNAME:S/emacs/emacs20/}
PKGREVISION=	26
CATEGORIES=	editors
MASTER_SITES=	http://ftp.gnu.org/pub/old-gnu/emacs/
MASTER_SITES+=	ftp://ftp.gnu.org/pub/old-gnu/emacs
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=	${DISTNAME}-mule-4.1b-elc${EXTRACT_SUFX}
SITES.${DISTNAME}-mule-4.1b-elc.tar.gz=	${MASTER_SITE_LOCAL}

# Mule enhancement (back port) patch by Satoshi Yatagawa
SITES.emacs-20.7-mule-4.1b.patch=	\
			http://www.teu.ac.jp/nsit/~yatagawa/comp/emacs/
PATCHFILES=		emacs-20.7-mule-4.1b.patch
# XIM fix patch by Seiichiro Inoue
SITES.emacs20-xim-20000713.diff=	\
			http://home.catv.ne.jp/pp/ginoue/software/emacs-xim/
PATCHFILES+=		emacs20-xim-20000713.diff

# dholland's jumbo patch
PATCHFILES+=		emacs20-jumbo-patch-20170723.gz
SITES.emacs20-jumbo-patch-20170723.gz= \
			http://www.NetBSD.org/~dholland/patchkits/emacs20/

PATCH_DIST_STRIP=	-p1

MAINTAINER=	dholland@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/emacs/emacs.html
COMMENT=	GNU editing macros (editor)

# configure: error: Emacs hasn't been ported to `x86_64-apple-darwin17' systems.
BROKEN_ON_PLATFORM=	Darwin-*-* DragonFly-*-*

CONFLICTS=	mule-[0-9]*

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
GNU_ARCH.mipsbe=	mips

MKPIE_SUPPORTED=	no

# build PATH in the dumped emacs is not a problem
CHECK_WRKREF_SKIP+=	bin/emacs
CHECK_WRKREF_SKIP+=	bin/emacs-20.7

.include "../../mk/bsd.prefs.mk"

# If using GNU ld 2.13.2.1 or later, avoid creating combined reloc
# sections and .data reloc sections, both of which Emacs can't handle
# properly.  Analyzed by Stephen Ma.
LDFLAGS+=	-Wl,-z,nocombreloc

.if (${OPSYS} == "NetBSD") && \
    !exists(/usr/lib/libgcc_s.so) && !exists(/usr/lib/libgcc.a)
# NetBSD with native Clang doesn't provide libgcc, everything is in libc.
pre-configure: fake-libgcc

fake-libgcc:
	${AR} q ${BUILDLINK_DIR}/lib/libgcc.a
.endif

# NetBSD < 5.99.24 uses termcap; afterwards terminfo. Emacs needs to be told.
.if (${OPSYS} == "NetBSD") && !exists(/usr/include/term.h)
CPPFLAGS+=	-D__NETBSD_USE_TERMCAP__
.endif

.if (${OPSYS} == "DragonFly") && exists(/usr/lib/crtn.o)
CPPFLAGS+=	-DDFLY_CRT_USRLIB
.endif

.include "options.mk"

MAKE_ENV+=	INSTALL_STRIP=${_STRIPFLAG_INSTALL:Q}

.include "../../mk/compiler.mk"
.if !empty(CC_VERSION:Mgcc-3.*)
CFLAGS+=	-fno-zero-initialized-in-bss
.endif

.if !empty(PKGSRC_COMPILER:Mclang)
TOOL_DEPENDS+=	tradcpp-[0-9]*:../../devel/tradcpp
MAKEFILECPP=	${PREFIX}/bin/tradcpp
.else
MAKEFILECPP=	${CPP} -traditional-cpp
.endif
ALL_ENV+=	MAKEFILECPP=${MAKEFILECPP:Q}

# emacs-20.7/lib-src/etags.c: In function 'init':
# emacs-20.7/lib-src/etags.c:1208:35: error: array subscript has type 'char' [-Werror=char-subscripts]
#    for (sp = white; *sp; sp++) _wht[*sp] = TRUE;    _wht[0] = _wht['\n'];
#                                    ^
# Maybe fix this later.
BUILDLINK_TRANSFORM+=	rm:-Werror=char-subscripts

INFO_FILES=	yes

INSTALL_PROGRAM=	${INSTALL} ${COPY} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}

post-extract:
	${CP} ${FILESDIR}/amd64.h ${WRKSRC}/src/m
	${CP} ${FILESDIR}/dragonfly.h ${WRKSRC}/src/s

pre-install:
	@${FIND} ${WRKSRC} -type f -name "*.orig*" -print | ${XARGS} ${RM} -f

post-install:
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${PREFIX}/share/emacs

.include "../../mk/bsd.pkg.mk"
