# $NetBSD: Makefile,v 1.4 2024/05/05 21:27:35 wiz Exp $

DISTNAME=	ecb-2.50
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel

MASTER_SITES=	${MASTER_SITE_GITHUB:=ecb-home/}
GITHUB_TAG=	1330a44cf3c171781083b0b926ab7622f64e6e81

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	https://github.com/ecb-home/ecb
COMMENT=	Emacs Code Browser
LICENSE=	gnu-gpl-v2

USE_TOOLS=	find gmake makeinfo tar
INFO_FILES=	yes

EMACS_VERSIONS_ACCEPTED=	emacs21 emacs21nox xemacs215 xemacs215nox xemacs214 xemacs214nox

MAKE_FLAGS+=		EMACS=${EMACS_BIN}
MAKE_FLAGS+=		SHELL=${SH:Q}
EMACS_MODULES=		base
EMACS_BUILDLINK=	yes

INSTALLATION_DIRS+=	\
	${PKGINFODIR} \
	${EMACS_LISPPREFIX}/${PKGBASE}

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.el  ${DESTDIR}${EMACS_LISPPREFIX}/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/*.elc ${DESTDIR}${EMACS_LISPPREFIX}/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/info-help/ecb.info* ${DESTDIR}${PREFIX}/${PKGINFODIR}
	${TAR} -cf - -C ${WRKSRC} ecb-images | \
		${TAR} -xf - -C ${DESTDIR}${EMACS_LISPPREFIX}/${PKGBASE}

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
