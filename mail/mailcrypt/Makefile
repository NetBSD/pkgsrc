# $NetBSD: Makefile,v 1.3 2002/02/18 15:14:27 seb Exp $
# FreeBSD Id: ports/mail/mailcrypt/Makefile,v 1.7 2000/05/14 05:21:52 billf Exp

DISTNAME=	mailcrypt-3.5.6
CATEGORIES=	mail security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mailcrypt/}

MAINTAINER=	sommerfeld@netbsd.org
HOMEPAGE=	http://mailcrypt.sourceforge.net/
COMMENT=	Emacs frontend for PGP and GPG

BUILD_DEPENDS=	emacs>=19.34:../../editors/emacs

GNU_CONFIGURE=	yes

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
