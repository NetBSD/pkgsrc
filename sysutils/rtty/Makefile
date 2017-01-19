# $NetBSD: Makefile,v 1.33 2017/01/19 18:52:26 agc Exp $

DISTNAME=	rtty-3.2
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://gatekeeper.hpl.hp.com/archive/pub/misc/vixie/
MASTER_SITES+=	ftp://gatekeeper.hpl.hp.com/pub/misc/vixie/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Multiuser "tip"/"cu" replacement with logging

WRKSRC=		${WRKDIR}

CFLAGS.SunOS+=	-Du_int16_t=uint16_t -Du_int32_t=uint32_t

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Darwin"
MAKE_ENV+=	LIBS="-lcrypt"
.endif

# If you need to regenerate patch-aa for Makefile, you should save
# your changes, run "make clean patch", apply your changes again,
# regenerate the diff for patch-aa. Same applies for any other files
# with /usr/local in them, should they acquire patches.
#
# This cannot be moved to pre-patch, because ${PREFIX} can differ
# between installations.

pre-configure:
	${CHMOD} u+w ${WRKDIR}/*
	for f in `echo ${WRKDIR}/* | ${XARGS} ${GREP} -l '/usr/local'`; do \
		${ECHO} patching $$f ; \
		${SED} -e 's:/usr/local:${PREFIX}:g' $$f > $$f.pdone && ${MV} $$f.pdone $$f; \
	done
	cd ${WRKDIR} && \
		${SED} -e '/^agelog=/s:/usr/etc/:${PREFIX}/rtty/bin/:' agelogs.sh >agelogs.sh.pdone && ${MV} agelogs.sh.pdone agelogs.sh

INSTALLATION_DIRS=	share/doc/rtty
INSTALL_MAKE_FLAGS+=	DESTROOT=${DESTDIR}

post-install:
	${INSTALL_DATA}  ${WRKDIR}/README ${DESTDIR}${PREFIX}/share/doc/rtty/

.include "../../mk/bsd.pkg.mk"
