# $NetBSD: Makefile,v 1.6 2007/02/02 16:03:07 joerg Exp $

DISTNAME=	epg-0.0.10
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME:S/epg/EasyPG/}
PKGREVISION=	1
CATEGORIES=	security mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=epg/23770/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.easypg.org/
COMMENT=	GnuPG interface for emacs

GNU_CONFIGURE=	YES
MAKE_FLAGS+=	lispdir=${EMACS_LISPPREFIX:Q}

# per README, GnuPG 1.4.3 and GNU Emacs 21.4 or XEmacs 21.4
DEPENDS+=	gnupg>=1.4.3:../../security/gnupg
EMACS_VERSIONS_ACCEPTED= emacs21 emacs21nox xemacs214 xemacs215

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
