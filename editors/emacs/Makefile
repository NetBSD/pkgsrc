# $NetBSD: Makefile,v 1.18 1998/08/31 20:29:27 tron Exp $
# FreeBSD Id: Makefile,v 1.30 1997/12/14 02:03:53 asami Exp
#

DISTNAME=	emacs-20.3
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/emacs/emacs.html

CONFLICTS=	emacs-20.2

GNU_CONFIGURE=	yes
#USE_GMAKE=	yes
CONFIGURE_ARGS+=	--with-pop --with-x --with-x-toolkit=lucid
OPSYS!=         uname -s
MAKE_ENV+=	INSTALL_STRIP=${STRIPFLAG} \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}"
INFO_FILES=	emacs vip viper forms gnus mh-e cl sc dired-x ediff ccmode message

post-install:
	${RM} -f ${PREFIX}/share/emacs/20.3/etc/DOC-20.3.[13-9]*
	chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/emacs
.if (${OPSYS} != "NetBSD")
	if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi
.endif

.include "../../mk/bsd.pkg.mk"
