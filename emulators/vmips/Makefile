# $NetBSD: Makefile,v 1.14 2020/03/20 11:57:36 nia Exp $

DISTNAME=		vmips-1.5.1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=vmips/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://vmips.sourceforge.net/
COMMENT=		MIPS R3000 emulator
LICENSE=		gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
INFO_FILES=		yes
INSTALLATION_DIRS=	bin include/vmips ${PKGMANDIR}/man1 share/vmips share/examples/vmips
INSTALL_MAKE_FLAGS+=	${MAKE_FLAGS} sysconfdir=${EGDIR:Q}

EGDIR=			${PREFIX}/share/examples/vmips
CONF_FILES=		${EGDIR}/vmipsrc ${PKG_SYSCONFDIR}/vmipsrc

USE_LANGUAGES=		c c++

TEST_DEPENDS+=		dejagnu-[0-9]*:../../devel/dejagnu
TEST_DIRS=		test_code
# needs mipsel-ecoff-gcc
#TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
