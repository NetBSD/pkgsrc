# $NetBSD: Makefile,v 1.9 2000/08/10 17:50:04 pooka Exp $
#

.include		"../nethack-lib/Makefile.common"

PKGNAME=		nethack-lib-${NETHACK_VERSION}

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./sys/unix/setup.sh
ALL_TARGET=		datastuff
INSTALL_TARGET=		manpages install-dat

DEINSTALL_FILE=		${WRKDIR}/DEINSTALL

.if ${OPSYS} == "SunOS"
MAKE_FLAGS+=     	CC=gcc CPPFLAGS=
.endif

post-build:
	${SED} -e 's|@PREFIX@|${PREFIX}|' ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}

.include "../../mk/bsd.pkg.mk"
