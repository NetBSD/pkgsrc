# $NetBSD: Makefile,v 1.9 2005/03/24 21:12:56 wiz Exp $

DISTNAME=	mailcrypt-3.5.8
CATEGORIES=	mail security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mailcrypt/}

MAINTAINER=	sommerfeld@NetBSD.org
HOMEPAGE=	http://mailcrypt.sourceforge.net/
COMMENT=	Emacs frontend for PGP and GPG

# What we would like to say here is: "we want GNU emacs"
EMACS_VERSIONS_ACCEPTED=       emacs21 emacs21nox emacs20

GNU_CONFIGURE=	yes
MAKE_ENV+=	EMACS_LISPPREFIX=${EMACS_LISPPREFIX}

INFO_FILES=	mailcrypt.info

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
