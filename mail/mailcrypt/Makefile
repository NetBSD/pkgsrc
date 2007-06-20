# $NetBSD: Makefile,v 1.14 2007/06/20 11:42:23 markd Exp $

DISTNAME=	mailcrypt-3.5.8
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	1
CATEGORIES=	mail security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mailcrypt/}

MAINTAINER=	sommerfeld@NetBSD.org
HOMEPAGE=	http://mailcrypt.sourceforge.net/
COMMENT=	Emacs frontend for PGP and GPG

# What we would like to say here is: "we want GNU emacs"
EMACS_VERSIONS_ACCEPTED=	emacs22 emacs22nox emacs21 emacs21nox emacs20

GNU_CONFIGURE=	yes
MAKE_FLAGS+=	lispdir=${EMACS_LISPPREFIX:Q}
INFO_FILES=	# PLIST

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
