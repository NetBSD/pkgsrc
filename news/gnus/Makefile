# $NetBSD: Makefile,v 1.2 2001/09/27 23:18:33 jlam Exp $
#

DISTNAME=	gnus-5.8.8
CATEGORIES=	news mail
MASTER_SITES=	ftp://ftp.gnus.org/pub/gnus/

MAINTAINER=	perry@netbsd.org
HOMEPAGE=	http://www.gnus.org/
COMMENT=	News/Mail reader for Emacs

# XXX Someone who cares can make this work with Xemacs.
DEPENDS+=	emacs-[0-9]*:../../editors/emacs

USE_GTEXINFO=	YES
GNU_CONFIGURE=	YES

.include "../../mk/bsd.pkg.mk"
