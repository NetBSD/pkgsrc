# $NetBSD: Makefile,v 1.16 2001/02/17 17:40:21 wiz Exp $
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

# If you want to build a static binary, uncomment the following line
#LDFLAGS+=-static

post-install:
	${CP} /etc/shells /etc/shells.bak
	(${GREP} -v ${PREFIX}/bin/zsh /etc/shells.bak; ${ECHO} ${PREFIX}/bin/zsh) >/etc/shells
	${RM} /etc/shells.bak

.include "../../mk/bsd.pkg.mk"
