# $NetBSD: Makefile,v 1.11 1998/08/04 20:19:51 tv Exp $
# FreeBSD Id: Makefile,v 1.17 1996/12/17 05:18:09 asami Exp
#

DISTNAME=       tcsh-6.07
PKGNAME=        tcsh-6.07.02
CATEGORIES=	shells
MASTER_SITES=   ftp://ftp.astron.com/pub/tcsh/

MAINTAINER=     packages@netbsd.org

GNU_CONFIGURE=  yes
WRKSRC=         ${WRKDIR}/${PKGNAME}
ALL_TARGET=     all catalogs
INSTALL_TARGET= install install.man

post-patch:
	( cd ${WRKSRC}/nls/greek ; for i in * ; do ${ECHO} $$i ; ${MV} $$i $$i.BAK ; ${SED} -e 's/\\"/"/g' -e "s/\\\'/'/g" <$$i.BAK >$$i ; done )

post-install:
	cd ${WRKSRC}; ${INSTALL_DATA} tcsh.C.cat ${PREFIX}/share/nls/C/tcsh.cat
	cd ${WRKSRC}; ${INSTALL_DATA} tcsh.french.cat ${PREFIX}/share/nls/fr_FR.ISO_8859-1/tcsh.cat
	ln -f ${PREFIX}/share/nls/fr_FR.ISO_8859-1/tcsh.cat ${PREFIX}/share/nls/fr_BE.ISO_8859-1/tcsh.cat
	ln -f ${PREFIX}/share/nls/fr_FR.ISO_8859-1/tcsh.cat ${PREFIX}/share/nls/fr_CA.ISO_8859-1/tcsh.cat
	ln -f ${PREFIX}/share/nls/fr_FR.ISO_8859-1/tcsh.cat ${PREFIX}/share/nls/fr_CH.ISO_8859-1/tcsh.cat
	cd ${WRKSRC}; ${INSTALL_DATA} tcsh.german.cat ${PREFIX}/share/nls/de_DE.ISO_8859-1/tcsh.cat
	ln -f ${PREFIX}/share/nls/de_DE.ISO_8859-1/tcsh.cat ${PREFIX}/share/nls/de_AT.ISO_8859-1/tcsh.cat
	ln -f ${PREFIX}/share/nls/de_DE.ISO_8859-1/tcsh.cat ${PREFIX}/share/nls/de_CH.ISO_8859-1/tcsh.cat
	${INSTALL_DATA_DIR} ${PREFIX}/share/nls/el_GR.ISO_8859-7
	cd ${WRKSRC}; ${INSTALL_DATA} tcsh.greek.cat ${PREFIX}/share/nls/el_GR.ISO_8859-7/tcsh.cat
	${ECHO} "updating /etc/shells"; ${CP} /etc/shells /etc/shells.bak; (grep -v ${PREFIX}/bin/tcsh /etc/shells.bak; ${ECHO} ${PREFIX}/bin/tcsh) >/etc/shells

.include "../../mk/bsd.pkg.mk"
