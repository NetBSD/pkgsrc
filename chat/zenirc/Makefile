# $NetBSD: Makefile,v 1.2 2001/09/27 23:17:49 jlam Exp $
#

DISTNAME=	zenirc-2.112
CATEGORIES=	chat
MASTER_SITES=	ftp://ftp.splode.com/pub/zenirc/

MAINTAINER=	thorpej@netbsd.org
HOMEPAGE=	http://www.splode.com/~friedman/software/emacs-lisp/zenirc/
COMMENT=	IRC client for Emacs

# XXX Someone who cares can make this work with Xemacs.
DEPENDS+=	emacs-[0-9]*:../../editors/emacs

USE_GTEXINFO=	YES
GNU_CONFIGURE=	YES

.include "../../mk/bsd.pkg.mk"
