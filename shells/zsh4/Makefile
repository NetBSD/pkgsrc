# $NetBSD: Makefile,v 1.1.1.1 2001/06/05 04:08:24 jtb Exp $

DISTNAME=       zsh-4.0.1
CATEGORIES=	shells
MASTER_SITES=   ftp://ftp.rge.com/pub/shells/zsh/ \
		ftp://sunsite.auc.dk/pub/unix/shells/zsh/ \
		ftp://ftp.uit.no/pub/unix/shells/zsh/ \
		ftp://ftp.cenatls.cena.dgac.fr/shells/zsh/ \
		ftp://ftp.net.lut.ac.uk/zsh/ \
		ftp://ftp.zsh.org/zsh/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	uebayasi@soum.co.jp
HOMEPAGE=	http://sunsite.auc.dk/zsh/
COMMENT=	The Z shell

GNU_CONFIGURE=	yes
INFO_FILES=	zsh.info

PLIST_SRC=	${PKGDIR}/PLIST

.include "../../mk/bsd.prefs.mk"

.if defined(ZSH_STATIC)
LDFLAGS+=	-static
.else
PLIST_SRC+=	${PKGDIR}/PLIST.dynamic
.endif

post-install:
	@cd ${WRKSRC}/Doc; ${MAKE} install.info
	${CP} /etc/shells /etc/shells.bak
	(${GREP} -v ${PREFIX}/bin/zsh /etc/shells.bak; ${ECHO} ${PREFIX}/bin/zsh) >/etc/shells
	${RM} /etc/shells.bak

.include "../../mk/bsd.pkg.mk"
