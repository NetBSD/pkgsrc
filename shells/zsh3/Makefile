# $NetBSD: Makefile,v 1.1.1.1 2001/06/05 16:30:14 jtb Exp $

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

.include "../../mk/bsd.prefs.mk"

.if defined(ZSH_STATIC)
LDFLAGS+=	-static
.endif

post-install:
	${CP} /etc/shells /etc/shells.bak
	(${GREP} -v ${PREFIX}/bin/zsh /etc/shells.bak; ${ECHO} ${PREFIX}/bin/zsh) >/etc/shells
	${RM} /etc/shells.bak

.include "../../mk/bsd.pkg.mk"
