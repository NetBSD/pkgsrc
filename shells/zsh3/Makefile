# $NetBSD: Makefile,v 1.20 2006/10/04 21:58:52 wiz Exp $
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
HOMEPAGE=	http://zsh.dotsrc.org/
COMMENT=	The Z shell

GNU_CONFIGURE=	yes
USE_TOOLS+=	makeinfo
INFO_FILES=	# PLIST

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	ZSH_STATIC

.if defined(ZSH_STATIC) && !empty(ZSH_STATIC:M[Yy][Ee][Ss])
LDFLAGS+=	-static
.endif

PKG_SHELL=	bin/zsh

.include "../../mk/bsd.pkg.mk"
