# $NetBSD: Makefile,v 1.32 2007/12/02 12:14:01 wiz Exp $

DISTNAME=	vm-7.19
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.uni-mainz.de/pub/software/gnu/vm/ \
		ftp://tug.org/vm/ \
		ftp://psg.com/pub/vm/ \
		ftp://sunsite.cnlab-switch.ch/mirror/vm/ \
		ftp://ftp.uu.net/networking/mail/vm/ \
		http://www.interhack.net/projects/vm/ \
		ftp://ftp.ccs.neu.edu/net/mirrors/VM/ \
		http://ftp.lip6.fr/pub/unix/mail/vm/ \
		http://ftp.jussieu.fr/pub/unix/mail/vm/ \
		ftp://ftp.surfnet.nl/pub/mail/vm/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.wonderworks.com/vm/
COMMENT=	VM (View Mail) is an advanced mail user agent for Emacs

USE_TOOLS+=	makeinfo
INFO_FILES=	# PLIST

MAKEFLAGS+=	EMACS=${EMACS_BIN:Q}
MAKE_ENV+=	LISPDIR=${EMACS_LISPPREFIX}/vm
MAKE_ENV+=	INFODIR=${INFODIR:Q}
MAKE_ENV+=	PIXMAPDIR=${PIXMAPDIR:Q}
MAKE_ENV+=	BINDIR=${PREFIX:Q}/bin
PLIST_SUBST+=	PIXMAPDIR=${PIXMAPDIR:S/^${PREFIX}\///:Q}

INSTALLATION_DIRS=	bin ${EMACS_INFOPREFIX} ${EMACS_LISPPREFIX}/vm	\
			${PIXMAPDIR}

PIXMAPDIR=		${PIXMAPDIR.${EMACS_FLAVOR}}
PIXMAPDIR.emacs=	${EMACS_LISPPREFIX}/vm/pixmaps
PIXMAPDIR.xemacs=	${EMACS_LISPPREFIX:H}/etc/vm

do-install:
	cd ${WRKSRC} && ${INSTALL_DATA} *.el* ${EMACS_LISPPREFIX}/vm
	cd ${WRKSRC}; for f in *.info *.info-[0-9]*; do			\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${EMACS_INFOPREFIX};		\
	done
	${INSTALL_DATA} ${WRKSRC}/pixmaps/*.x[pb]m ${PIXMAPDIR}
	cd ${WRKSRC} && ${INSTALL_PROGRAM} qp-decode qp-encode		\
		base64-decode base64-encode ${PREFIX}/bin

.include "../../mk/emacs.mk"

.include "../../mk/bsd.pkg.mk"
