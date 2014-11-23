# $NetBSD: Makefile,v 1.25 2014/11/23 06:08:29 mef Exp $

DISTNAME=	mailcrypt-3.5.9
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=	mail security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mailcrypt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mailcrypt.sourceforge.net/
COMMENT=	Emacs frontend for PGP and GPG

# What we would like to say here is: "we want GNU emacs"
EMACS_VERSIONS_ACCEPTED=	emacs25 \
				emacs24 emacs24nox \
				emacs23 emacs23nox \
				emacs22 emacs22nox \
				emacs21 emacs21nox \
				emacs20

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
