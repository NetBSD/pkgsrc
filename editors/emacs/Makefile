# $NetBSD: Makefile,v 1.42 2001/05/19 03:56:34 jlam Exp $
# FreeBSD Id: Makefile,v 1.30 1997/12/14 02:03:53 asami Exp

DISTNAME=	emacs-20.7
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU:=emacs/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/emacs/emacs.html
COMMENT=	GNU editing macros (editor)

CONFLICTS=	mule-*

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

BUILD_DEFS+=	USE_INET6 EMACS_USE_POP EMACS_USE_X EMACS_USE_X_TOOLKIT

.include "../../mk/bsd.prefs.mk"

EMACS_USE_POP?=	yes
.if (defined(EMACS_USE_POP) && \
    (${EMACS_USE_POP} == yes || ${EMACS_USE_POP} == YES))
CONFIGURE_ARGS+=--with-pop
.endif
.if defined(EMACS_USE_X)
CONFIGURE_ARGS+=--with-x=${EMACS_USE_X}
.endif
.if defined(EMACS_USE_X_TOOLKIT)
CONFIGURE_ARGS+=--with-x-toolkit=${EMACS_USE_X_TOOLKIT}
.endif
.if (defined(USE_INET6) && ${USE_INET6} == NO)
CONFIGURE_ARGS+=--without-ipv6
.else
CONFIGURE_ARGS+=--with-ipv6
.endif
MAKE_ENV+=	INSTALL_STRIP=${STRIPFLAG}
INFO_FILES=	emacs vip viper forms gnus mh-e cl sc dired-x ediff \
		    ccmode message widget reftex forms

INSTALL_PROGRAM=${INSTALL} ${COPY} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}

pre-install:
	@${FIND} ${WRKSRC} -type f -name "*.orig" | ${XARGS} ${RM} -f

post-install:
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/emacs

.include "../../mk/bsd.pkg.mk"
