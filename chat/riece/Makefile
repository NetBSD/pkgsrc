# $NetBSD: Makefile,v 1.20 2012/10/03 00:02:43 asau Exp $
#

DISTNAME=	riece-5.0.0
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	1
CATEGORIES=	chat japanese
MASTER_SITES=	http://download.savannah.gnu.org/releases/riece/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/riece/
COMMENT=	IRC client for Emacs

INSTALLATION_DIRS=	${EMACS_LISPPREFIX:C|^${PREFIX}/||}/riece \
			${EMACS_INFOPREFIX:C|^${PREFIX}/||}

EMACS_VERSIONS_ACCEPTED= \
		emacs23 emacs23nox emacs22 emacs22nox emacs21 emacs21nox \
		xemacs215 xemacs215nox xemacs214 xemacs214nox
EMACS_MODULES=	base

WRKSRC=		${WRKDIR}/${DISTNAME:C|[^0-9]$||}

GNU_CONFIGURE=	YES
INFO_FILES=	# PLIST

# --with-emacs=... or --with-xemacs=...
CONFIGURE_ARGS+=	--with-${EMACS_FLAVOR}=${EMACS_BIN:Q}
CONFIGURE_ARGS+=	${CONFIGURE_ARGS.${EMACS_FLAVOR}}

# Riece digs sub directory.
CONFIGURE_ARGS.emacs=	--with-lispdir=${EMACS_LISPPREFIX:Q}
CONFIGURE_ARGS.xemacs=	--with-packagedir=${EMACS_LISPPREFIX:C|/lisp\$||}

do-install: plist
	${INSTALL_DATA} ${WRKSRC}/doc/*.info ${DESTDIR}${EMACS_INFOPREFIX}
	cd ${WRKSRC}/lisp;						\
	grep -v '^@' ${PLIST} | grep '/site-lisp/riece/' |		\
	while read file; do						\
		file=$$( basename $$file );				\
		${INSTALL_DATA} $$file ${DESTDIR}${EMACS_LISPPREFIX}/riece; \
	done

.include "../../editors/emacs/modules.mk"

.include "../../mk/bsd.pkg.mk"
