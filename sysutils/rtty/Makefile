# $NetBSD: Makefile,v 1.13 2001/05/19 03:56:40 jlam Exp $
# FreeBSD Id: Makefile,v 1.3 1997/01/06 12:13:36 jkh Exp
#

DISTNAME=       rtty-3.2
PKGNAME=	${DISTNAME}nb1
CATEGORIES=	sysutils
MASTER_SITES=   ftp://ftp.vix.com/pub/vixie/

MAINTAINER=	packages@netbsd.org
COMMENT=	multiuser "tip"/"cu" replacement with logging

NO_WRKSUBDIR=   yes

pre-configure:
	${CHMOD} -R u+w ${WRKDIR}
	for f in `${FIND} ${WRKDIR}/. -type f -print | ${XARGS} ${GREP} -l '/usr/local'`; do \
		${ECHO} patching $$f ; \
		${SED} -e 's:/usr/local:${PREFIX}:g' $$f > $$f.pdone && ${MV} $$f.pdone $$f; \
	done
	cd ${WRKDIR} && \
		${SED} -e '/^agelog=/s:/usr/etc/:${PREFIX}/rtty/bin/:' agelogs.sh >agelogs.sh.pdone && ${MV} agelogs.sh.pdone agelogs.sh

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/rtty
	${INSTALL_DATA}  ${WRKDIR}/README ${PREFIX}/share/doc/rtty/

.include "../../mk/bsd.pkg.mk"
