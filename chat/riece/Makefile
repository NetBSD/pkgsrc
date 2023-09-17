# $NetBSD: Makefile,v 1.34 2023/09/17 02:16:40 mef Exp $
#

DISTNAME=	riece-9.0.0
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	5
CATEGORIES=	chat japanese
MASTER_SITES=	http://download.savannah.gnu.org/releases/riece/
LICENSE=	gnu-gpl-v3

MAINTAINER=	makoto@ki.nu
HOMEPAGE=	https://www.nongnu.org/riece/
COMMENT=	IRC client for Emacs

INSTALLATION_DIRS=	${EMACS_LISPPREFIX:C|^${PREFIX}/||}/riece \
			${EMACS_INFOPREFIX:C|^${PREFIX}/||}

EMACS_VERSIONS_ACCEPTED= \
		emacs27 emacs26 emacs26nox emacs25 emacs25nox emacs21 emacs21nox \
		emacs28 emacs28nox \
		xemacs215 xemacs215nox xemacs214 xemacs214nox
EMACS_MODULES=	base

GNU_CONFIGURE=	YES
INFO_FILES=	yes

# --with-emacs=... or --with-xemacs=...
CONFIGURE_ARGS+=	--with-${EMACS_FLAVOR}=${EMACS_BIN}
CONFIGURE_ARGS+=	${CONFIGURE_ARGS.${EMACS_FLAVOR}}

# Riece digs sub directory.
CONFIGURE_ARGS.emacs=	--with-lispdir=${EMACS_LISPPREFIX}
CONFIGURE_ARGS.xemacs=	--with-packagedir=${EMACS_LISPPREFIX:C|/lisp\$||}

do-install: plist
	${INSTALL_DATA} ${WRKSRC}/doc/*.info ${DESTDIR}${EMACS_INFOPREFIX}
	cd ${WRKSRC}/lisp;						\
	grep -v '^@' ${PLIST} | 					\
		grep "${EMACS_LISPPREFIX:C|^${PREFIX}/||}/riece" |	\
	while read file; do						\
		file=$$( basename $$file );				\
		${INSTALL_DATA} $$file ${DESTDIR}${EMACS_LISPPREFIX}/riece; \
	done

.include "../../editors/emacs/modules.mk"

.include "../../mk/bsd.pkg.mk"
