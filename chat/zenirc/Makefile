# $NetBSD: Makefile,v 1.3 2002/02/18 15:14:03 seb Exp $
#

DISTNAME=	zenirc-2.112
CATEGORIES=	chat
MASTER_SITES=	ftp://ftp.splode.com/pub/zenirc/

MAINTAINER=	thorpej@netbsd.org
HOMEPAGE=	http://www.splode.com/~friedman/software/emacs-lisp/zenirc/
COMMENT=	IRC client for Emacs

# XXX Someone who cares can make this work with Xemacs.
DEPENDS+=	emacs-[0-9]*:../../editors/emacs

GNU_CONFIGURE=	YES

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
