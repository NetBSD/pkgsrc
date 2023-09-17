# $NetBSD: Makefile,v 1.31 2023/09/17 02:07:20 mef Exp $

DISTNAME=	mailcrypt-3.5.9
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	1
CATEGORIES=	mail security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mailcrypt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mailcrypt.sourceforge.net/
COMMENT=	Emacs frontend for PGP and GPG

# What we would like to say here is: "we want GNU emacs"
EMACS_VERSIONS_ACCEPTED=	emacs20
EMACS_VERSIONS_ACCEPTED+=	emacs21 emacs21nox
EMACS_VERSIONS_ACCEPTED+=	emacs26 emacs26nox
EMACS_VERSIONS_ACCEPTED+=	emacs28 emacs28nox

GNU_CONFIGURE=	yes
USE_TOOLS+=	autoconf makeinfo
MAKE_FLAGS+=	prefix=${DESTDIR:Q}${PREFIX:Q} \
		lispdir=${DESTDIR:Q}${EMACS_LISPPREFIX:Q} \
		infodir=${DESTDIR:Q}${PREFIX:Q}/${PKGINFODIR}
INFO_FILES=	yes

pre-configure:
		(cd ${WRKSRC}; autoconf)

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
