# $NetBSD: Makefile,v 1.26 1999/02/25 17:08:33 sommerfe Exp $
# FreeBSD Id: Makefile,v 1.30 1997/12/14 02:03:53 asami Exp
#

DISTNAME=	emacs-20.3
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/emacs/emacs.html

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS+=--with-pop --with-x --with-x-toolkit=lucid
OPSYS!=         uname -s
MAKE_ENV+=	INSTALL_STRIP=${STRIPFLAG}
INFO_FILES=	emacs vip viper forms gnus mh-e cl sc dired-x ediff ccmode message widget reftex forms customize

INSTALL_PROGRAM= ${INSTALL} ${COPY} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}

pre-install:
	@find ${WRKSRC} -type f -name "*.orig" | xargs ${RM} -f

post-build:
	(cd ${WRKSRC}/lisp/mail; \
	${WRKSRC}/src/emacs -batch -f batch-byte-compile mh-comp.el mh-utils.el)

post-install:
	chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/emacs

.include "../../mk/bsd.pkg.mk"
