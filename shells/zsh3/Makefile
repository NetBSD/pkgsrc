# $NetBSD: Makefile,v 1.11 2004/04/18 04:36:42 snj Exp $

DISTNAME=       zsh-3.0.8
CATEGORIES=	shells
MASTER_SITES=   ftp://ftp.rge.com/pub/shells/zsh/old/ \
		ftp://sunsite.auc.dk/pub/unix/shells/zsh/old/ \
		ftp://ftp.uit.no/pub/unix/shells/zsh/old/ \
		ftp://ftp.net.lut.ac.uk/zsh/old/ \
		ftp://ftp.zsh.org/zsh/old/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://sunsite.dk/zsh/
COMMENT=	The Z shell

GNU_CONFIGURE=	yes
USE_MAKEINFO=	YES
INFO_FILES=	zsh.info
USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES

.include "../../mk/bsd.prefs.mk"

.if defined(ZSH_STATIC)
LDFLAGS+=	-static
.endif

PKG_SHELL=	${PREFIX}/bin/zsh

.include "../../mk/bsd.pkg.mk"
