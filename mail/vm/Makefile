# $NetBSD: Makefile,v 1.43 2017/01/19 18:52:17 agc Exp $

DISTNAME=	vm-7.19
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.uni-mainz.de/pub/software/gnu/vm/
MASTER_SITES+=	ftp://tug.org/vm/
MASTER_SITES+=	ftp://psg.com/pub/vm/
MASTER_SITES+=	ftp://sunsite.cnlab-switch.ch/mirror/vm/
MASTER_SITES+=	http://www.interhack.net/projects/vm/
MASTER_SITES+=	http://ftp.lip6.fr/pub/unix/mail/vm/
MASTER_SITES+=	http://ftp.jussieu.fr/pub/unix/mail/vm/
MASTER_SITES+=	ftp://ftp.surfnet.nl/pub/mail/vm/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.wonderworks.com/vm/
COMMENT=	VM (View Mail) is an advanced mail user agent for Emacs

USE_TOOLS+=	makeinfo
INFO_FILES=	yes

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
	cd ${WRKSRC} && ${INSTALL_DATA} *.el *.elc ${DESTDIR}${EMACS_LISPPREFIX}/vm
	cd ${WRKSRC}; for f in *.info *.info-[0-9]*; do			\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${DESTDIR}${EMACS_INFOPREFIX};	\
	done
	${INSTALL_DATA} ${WRKSRC}/pixmaps/*.x[pb]m ${DESTDIR}${PIXMAPDIR}
	cd ${WRKSRC} && ${INSTALL_PROGRAM} qp-decode qp-encode		\
		base64-decode base64-encode ${DESTDIR}${PREFIX}/bin

.include "../../editors/emacs/modules.mk"

.include "../../mk/bsd.pkg.mk"
