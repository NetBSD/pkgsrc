# $NetBSD: Makefile,v 1.19 1998/09/01 20:04:33 mellon Exp $
# FreeBSD Id: Makefile,v 1.30 1997/12/14 02:03:53 asami Exp
#

DISTNAME=	emacs-20.3
WRKSRC=		${WRKDIR}/emacs-20.3
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	mellon@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/emacs/emacs.html

CONFLICTS=	emacs-20.2

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS+=	--with-pop --with-x --with-x-toolkit=lucid
OPSYS!=         uname -s
MAKE_ENV+=	INSTALL_STRIP=${STRIPFLAG} \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}"
INFO_FILES=	emacs vip viper forms gnus mh-e cl sc dired-x ediff ccmode message

INSTALL_PROGRAM= ${INSTALL} ${COPY} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}

post-install:
	${RM} -f ${PREFIX}/share/emacs/20.3/etc/DOC-20.3.[13-9]*
	chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/emacs
.if (${OPSYS} != "NetBSD")
	if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi
.endif

.include "../../mk/bsd.pkg.mk"
