# $NetBSD: Makefile,v 1.10 2003/08/09 11:23:00 seb Exp $

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
USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES

.include "../../mk/bsd.prefs.mk"

.if defined(ZSH_STATIC)
LDFLAGS+=	-static
.endif

PKG_SHELL=	${PREFIX}/bin/zsh

.include "../../mk/bsd.pkg.mk"
