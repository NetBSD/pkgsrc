# $NetBSD: Makefile,v 1.17 2001/04/09 00:35:38 jtb Exp $
#

DISTNAME=       zsh-3.0.7
CATEGORIES=	shells
MASTER_SITES=   ftp://uiarchive.uiuc.edu/pub/packages/shells/zsh/ \
		ftp://ftp.rge.com/pub/shells/zsh/ \
		ftp://sunsite.auc.dk/pub/unix/shells/zsh/ \
		ftp://ftp.uit.no/pub/unix/shells/zsh/ \
		ftp://ftp.cenatls.cena.dgac.fr/shells/zsh/ \
		ftp://ftp.net.lut.ac.uk/zsh/ \
		ftp://ftp.zsh.org/zsh/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://sunsite.auc.dk/zsh/
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
