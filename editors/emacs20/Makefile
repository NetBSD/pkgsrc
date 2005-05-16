# $NetBSD: Makefile,v 1.18 2005/05/16 21:05:27 minskim Exp $

DISTNAME=	emacs-20.7
PKGREVISION=	5
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU:=emacs/} \
		${MASTER_SITE_LOCAL}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME}-mule-4.1b-elc${EXTRACT_SUFX}

# Mule enhancement (back port) patch by Satoshi Yatagawa
PATCH_SITES=		http://www.teu.ac.jp/nsit/~yatagawa/comp/emacs/
PATCHFILES=		emacs-20.7-mule-4.1b.patch
# XIM fix patch by Seiichiro Inoue
PATCH_SITES+=		http://home.catv.ne.jp/pp/ginoue/software/emacs-xim/
PATCHFILES+=		emacs20-xim-20000713.diff
PATCH_DIST_STRIP=	-p1

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/emacs/emacs.html
COMMENT=	GNU editing macros (editor)

NOT_FOR_PLATFORM=	Darwin-*-*

CONFLICTS=	mule-[0-9]*

GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	make
GNU_ARCH.mipsbe= mips

BUILD_DEFS+=	USE_INET6 EMACS_USE_POP

.include "../../mk/bsd.prefs.mk"

# This matches NetBSD <1.7 releases and 1.6A-1.6P, where ld is <2.13.2.1.
.if ${OPSYS} == "NetBSD" && \
    (empty(OS_VERSION:M1.[0-5]*) && \
     empty(OS_VERSION:M1.6_*) && \
     empty(OS_VERSION:M1.6) && \
     empty(OS_VERSION:M1.6.[0-9]*) && \
     empty(OS_VERSION:M1.6[A-P]*))
# If using GNU ld 2.13.2.1 or later, avoid creating combined reloc
# sections and .data reloc sections, both of which Emacs can't handle
# properly.  Analyzed by Stephen Ma.
LDFLAGS+=	-Wl,-z,nocombreloc
.endif

EMACS_USE_POP?=	yes
.if (defined(EMACS_USE_POP) && \
    (${EMACS_USE_POP} == yes || ${EMACS_USE_POP} == YES))
CONFIGURE_ARGS+=--with-pop
.endif

.if defined(EMACS_USE_X)
BUILD_DEFS+=		EMACS_USE_X EMACS_USE_X_TOOLKIT
USE_X11=		yes
CONFIGURE_ARGS+=	--with-x=yes
.if defined(EMACS_USE_X_TOOLKIT)
CONFIGURE_ARGS+=	--with-x-toolkit=${EMACS_USE_X_TOOLKIT}
.if ${EMACS_USE_X_TOOLKIT} == "lucid" || ${EMACS_USE_X_TOOLKIT} == "athena"
.include "../../mk/xaw.buildlink3.mk"
.elif ${EMACS_USE_X_TOOLKIT} == "motif"
.include "../../mk/motif.buildlink3.mk"
.endif
.endif
.else
CONFIGURE_ARGS+=	--with-x=no
.endif	# EMACS_USE_X

.if defined(USE_INET6) && ${USE_INET6} == YES
CONFIGURE_ARGS+=--with-ipv6
.else
CONFIGURE_ARGS+=--without-ipv6
.endif
MAKE_ENV+=	INSTALL_STRIP=${_STRIPFLAG_INSTALL}

.include "../../mk/compiler.mk"
.if !empty(CC_VERSION:Mgcc-3.*)
CFLAGS+=	-fno-zero-initialized-in-bss
.endif

INFO_FILES=	emacs vip viper forms gnus mh-e cl sc dired-x ediff \
		    ccmode message widget reftex

INSTALL_PROGRAM=${INSTALL} ${COPY} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}

post-extract:
	${CP} ${FILESDIR}/amd64.h ${WRKSRC}/src/m

pre-install:
	@${FIND} ${WRKSRC} -type f -name "*.orig*" -print | ${XARGS} ${RM} -f

post-install:
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/emacs

.include "../../mk/bsd.pkg.mk"
