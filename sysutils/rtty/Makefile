# $NetBSD: Makefile,v 1.26 2008/04/19 06:07:50 obache Exp $

DISTNAME=	rtty-3.2
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://gatekeeper.hpl.hp.com/archive/pub/misc/vixie/ \
		ftp://gatekeeper.hpl.hp.com/pub/misc/vixie/

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
