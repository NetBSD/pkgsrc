# $NetBSD: Makefile,v 1.25 2006/12/17 20:09:26 minskim Exp $

DISTNAME=	rtty-3.2
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.vix.com/pub/vixie/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Multiuser "tip"/"cu" replacement with logging

WRKSRC=		${WRKDIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Darwin"
MAKE_ENV+=	LIBS="-lcrypt"
.endif

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
