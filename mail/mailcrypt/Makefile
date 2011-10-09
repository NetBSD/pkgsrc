# $NetBSD: Makefile,v 1.19 2011/10/09 02:27:54 kim Exp $

DISTNAME=	mailcrypt-3.5.8
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	2
CATEGORIES=	mail security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mailcrypt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mailcrypt.sourceforge.net/
COMMENT=	Emacs frontend for PGP and GPG

PKG_DESTDIR_SUPPORT=	user-destdir

# What we would like to say here is: "we want GNU emacs"
EMACS_VERSIONS_ACCEPTED=	emacs23 emacs23nox \
				emacs22 emacs22nox \
				emacs21 emacs21nox \
				emacs20

GNU_CONFIGURE=	yes
MAKE_FLAGS+=	prefix=${DESTDIR:Q}${PREFIX:Q} \
		lispdir=${DESTDIR:Q}${EMACS_LISPPREFIX:Q} \
		infodir=${DESTDIR:Q}${PREFIX:Q}/info
INFO_FILES=	# PLIST

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
