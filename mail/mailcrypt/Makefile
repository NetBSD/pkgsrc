# $NetBSD: Makefile,v 1.5 2003/07/17 21:46:22 grant Exp $
# FreeBSD Id: ports/mail/mailcrypt/Makefile,v 1.7 2000/05/14 05:21:52 billf Exp

DISTNAME=	mailcrypt-3.5.6
CATEGORIES=	mail security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mailcrypt/}

MAINTAINER=	sommerfeld@NetBSD.org
HOMEPAGE=	http://mailcrypt.sourceforge.net/
COMMENT=	Emacs frontend for PGP and GPG

# What we would like to say here is: "we want GNU emacs"
EMACS_VERSIONS_ACCEPTED=       emacs21 emacs21nox emacs20

GNU_CONFIGURE=	yes
MAKE_ENV+=	EMACS_LISPPREFIX=${EMACS_LISPPREFIX}

.include "../../mk/emacs.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
