# $NetBSD: Makefile,v 1.3 2003/04/24 15:00:16 jmc Exp $

DISTNAME=	emacs-20.7
PKGREVISION=	2
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

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/emacs/emacs.html
COMMENT=	GNU editing macros (editor)

CONFLICTS=	mule-[0-9]*

USE_BUILDLINK2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
GNU_ARCH.mipsbe= mips

BUILD_DEFS+=	USE_INET6 EMACS_USE_POP

.include "../../mk/bsd.prefs.mk"

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
.include "../../mk/xaw.buildlink2.mk"
.elif ${EMACS_USE_X_TOOLKIT} == "motif"
.include "../../mk/motif.buildlink2.mk"
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
INFO_FILES=	emacs vip viper forms gnus mh-e cl sc dired-x ediff \
		    ccmode message widget reftex forms

INSTALL_PROGRAM=${INSTALL} ${COPY} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}

pre-install:
	@${FIND} ${WRKSRC} -type f -name "*.orig" | ${XARGS} ${RM} -f

post-install:
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/emacs

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
