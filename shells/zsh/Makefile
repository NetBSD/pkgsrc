# $NetBSD: Makefile,v 1.13 1999/02/26 11:00:13 frueauf Exp $
# FreeBSD Id: Makefile,v 1.26 1997/09/26 08:23:14 torstenb Exp
#

DISTNAME=       zsh-3.0.5
CATEGORIES=	shells
MASTER_SITES=   ftp://ftp.math.gatech.edu/pub/zsh/ \
		ftp://uiarchive.uiuc.edu/pub/packages/shells/zsh/ \
		ftp://ftp.rge.com/pub/zsh/ \
		ftp://sunsite.auc.dk/pub/unix/shells/zsh/ \
		ftp://ftp.cenatls.cena.dgac.fr/pub/shells/zsh/ \
		ftp://ftp.net.lut.ac.uk/zsh/ \
		ftp://ftp.uit.no/pub/unix/shells/zsh/ \
		ftp://ftp.zsh.org/zsh/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://sunsite.auc.dk/zsh/

GNU_CONFIGURE=	yes
INFO_FILES=	zsh.info

# If you want to build a static binary, uncomment the following line
#LDFLAGS+=-static

post-install:
	${CP} /etc/shells /etc/shells.bak
	(${GREP} -v ${PREFIX}/bin/zsh /etc/shells.bak; ${ECHO} ${PREFIX}/bin/zsh) >/etc/shells
	${RM} /etc/shells.bak

.include "../../mk/bsd.pkg.mk"
