# $NetBSD: Makefile,v 1.21 2019/11/04 21:12:51 rillig Exp $

DISTNAME=	epg-0.0.16
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME:S/epg/EasyPG/}
PKGREVISION=	3
CATEGORIES=	security mail
MASTER_SITES=	${MASTER_SITE_OSDN:=epg/29289/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.easypg.org/
COMMENT=	GnuPG interface for emacs

GNU_CONFIGURE=		YES
MAKE_FLAGS+=		lispdir=${EMACS_LISPPREFIX:Q}
INSTALL_MAKE_FLAGS+=	lispdir=${DESTDIR}${EMACS_LISPPREFIX:Q}

INFO_FILES=	yes

# per README: GnuPG 1.4.3
DEPENDS+=	gnupg>=1.4.3:../../security/gnupg
# per README: GNU Emacs 21.4, XEmacs 21.4, or later
EMACS_VERSIONS_ACCEPTED= emacs21 emacs21nox xemacs214 xemacs215

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
