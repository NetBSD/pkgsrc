# $NetBSD: Makefile,v 1.18 2006/03/05 16:27:28 jlam Exp $
#

DISTNAME=       zsh-3.0.8
PKGREVISION=	1
CATEGORIES=	shells
MASTER_SITES=   ftp://ftp.rge.com/pub/shells/zsh/old/ \
		ftp://sunsite.auc.dk/pub/unix/shells/zsh/old/ \
		ftp://ftp.uit.no/pub/unix/shells/zsh/old/ \
		ftp://ftp.net.lut.ac.uk/zsh/old/ \
		ftp://ftp.zsh.org/zsh/old/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sunsite.dk/zsh/
COMMENT=	The Z shell

GNU_CONFIGURE=	yes
USE_TOOLS+=	makeinfo
INFO_FILES=	zsh.info

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	ZSH_STATIC

.if defined(ZSH_STATIC) && !empty(ZSH_STATIC:M[Yy][Ee][Ss])
LDFLAGS+=	-static
.endif

PKG_SHELL=	bin/zsh

.include "../../mk/bsd.pkg.mk"
