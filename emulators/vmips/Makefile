# $NetBSD: Makefile,v 1.10 2013/05/16 05:17:45 shattered Exp $
#

DISTNAME=		vmips-1.4.1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=vmips/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://vmips.sourceforge.net/
COMMENT=		MIPS R3000 emulator

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
INFO_FILES=		yes
INSTALLATION_DIRS=	bin include/vmips ${PKGMANDIR}/man1 share/vmips share/examples/vmips
INSTALL_MAKE_FLAGS+=	${MAKE_FLAGS} sysconfdir=${EGDIR:Q}

EGDIR=			${PREFIX}/share/examples/vmips
CONF_FILES=		${EGDIR}/vmipsrc ${PKG_SYSCONFDIR}/vmipsrc

USE_LANGUAGES=		c c++

do-test:
	if ${PKG_INFO} -qe dejagnu; then		\
		(cd ${WRKSRC}/test_code && ${MAKE} check);	\
	else						\
		${ECHO} "dejagnu is required for the test target";	\
	fi

.include "../../mk/bsd.pkg.mk"
