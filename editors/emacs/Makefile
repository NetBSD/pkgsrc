# $NetBSD: Makefile,v 1.17 1998/08/20 15:16:51 tsarna Exp $
# FreeBSD Id: Makefile,v 1.30 1997/12/14 02:03:53 asami Exp
#

DISTNAME=	emacs-20.2
WRKSRC=		${WRKDIR}/emacs-20.2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/emacs/emacs.html

GNU_CONFIGURE=	yes
#USE_GMAKE=	yes
CONFIGURE_ARGS+=	--with-pop --with-x --with-x-toolkit=lucid
OPSYS!=         uname -s
MAKE_ENV+=	INSTALL_STRIP=${STRIPFLAG} \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}"
INFO_FILES=	emacs vip viper forms gnus mh-e cl sc dired-x ediff ccmode message

post-build:
	(cd ${WRKSRC}/lisp/mail; \
	${WRKSRC}/src/emacs -batch -f batch-byte-compile mh-funcs.el mh-utils.el)

post-install:
	${RM} -f ${PREFIX}/share/emacs/20.2/etc/DOC-20.2.[13-9]*
	chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/emacs
.if (${OPSYS} != "NetBSD")
	if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi
.endif

.include "../../mk/bsd.pkg.mk"
