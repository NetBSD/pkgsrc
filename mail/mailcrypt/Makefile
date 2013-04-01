# $NetBSD: Makefile,v 1.23 2013/04/01 05:53:24 sbd Exp $

DISTNAME=	mailcrypt-3.5.8
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	3
CATEGORIES=	mail security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mailcrypt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mailcrypt.sourceforge.net/
COMMENT=	Emacs frontend for PGP and GPG

# What we would like to say here is: "we want GNU emacs"
EMACS_VERSIONS_ACCEPTED=	emacs24 emacs24nox \
				emacs23 emacs23nox \
				emacs22 emacs22nox \
				emacs21 emacs21nox \
				emacs20

GNU_CONFIGURE=	yes
MAKE_FLAGS+=	prefix=${DESTDIR:Q}${PREFIX:Q} \
		lispdir=${DESTDIR:Q}${EMACS_LISPPREFIX:Q} \
		infodir=${DESTDIR:Q}${PREFIX:Q}/${PKGINFODIR}
INFO_FILES=	# PLIST

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
