# $NetBSD: Makefile,v 1.5 2002/12/23 13:03:39 seb Exp $

DISTNAME=       zsh-3.0.8
CATEGORIES=	shells
MASTER_SITES=   ftp://ftp.rge.com/pub/shells/zsh/old/ \
		ftp://sunsite.auc.dk/pub/unix/shells/zsh/old/ \
		ftp://ftp.uit.no/pub/unix/shells/zsh/old/ \
		ftp://ftp.net.lut.ac.uk/zsh/old/ \
		ftp://ftp.zsh.org/zsh/old/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://sunsite.dk/zsh/
COMMENT=	The Z shell

GNU_CONFIGURE=	yes
INFO_FILES=	zsh.info
TEXINFO_OVERRIDE=	YES
USE_BUILDLINK2=		YES

.include "../../mk/bsd.prefs.mk"

.if defined(ZSH_STATIC)
LDFLAGS+=	-static
.endif

PKG_SHELL=	${PREFIX}/bin/zsh

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
