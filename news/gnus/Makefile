# $NetBSD: Makefile,v 1.3 2002/02/18 15:14:37 seb Exp $
#

DISTNAME=	gnus-5.8.8
CATEGORIES=	news mail
MASTER_SITES=	ftp://ftp.gnus.org/pub/gnus/

MAINTAINER=	perry@netbsd.org
HOMEPAGE=	http://www.gnus.org/
COMMENT=	News/Mail reader for Emacs

# XXX Someone who cares can make this work with Xemacs.
DEPENDS+=	emacs-[0-9]*:../../editors/emacs

GNU_CONFIGURE=	YES
TEXINFO_OVERRIDE=	YES

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
