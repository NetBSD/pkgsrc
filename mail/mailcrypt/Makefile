# $NetBSD: Makefile,v 1.12 2006/02/05 23:09:55 joerg Exp $

DISTNAME=	mailcrypt-3.5.8
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	1
CATEGORIES=	mail security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mailcrypt/}

MAINTAINER=	sommerfeld@NetBSD.org
HOMEPAGE=	http://mailcrypt.sourceforge.net/
COMMENT=	Emacs frontend for PGP and GPG

# What we would like to say here is: "we want GNU emacs"
EMACS_VERSIONS_ACCEPTED=       emacs21 emacs21nox emacs20

GNU_CONFIGURE=	yes
MAKE_ENV+=	EMACS_LISPPREFIX=${EMACS_LISPPREFIX:Q}

INFO_FILES=	mailcrypt.info

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
