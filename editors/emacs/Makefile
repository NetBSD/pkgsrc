# $NetBSD: Makefile,v 1.20 1998/09/04 02:28:52 tron Exp $
# FreeBSD Id: Makefile,v 1.30 1997/12/14 02:03:53 asami Exp
#

DISTNAME=	emacs-20.3
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/emacs/emacs.html

CONFLICTS=	emacs-20.2

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS+=	--with-pop --with-x --with-x-toolkit=lucid
OPSYS!=         uname -s
MAKE_ENV+=	INSTALL_STRIP=${STRIPFLAG}
INFO_FILES=	emacs vip viper forms gnus mh-e cl sc dired-x ediff ccmode message widget reftex forms customize

INSTALL_PROGRAM= ${INSTALL} ${COPY} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}

pre-install:
	@find ${WRKSRC} -type f -name "*.orig" | xargs rm -f

post-install:
	chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/emacs

.include "../../mk/bsd.pkg.mk"
