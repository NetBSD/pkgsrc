# $NetBSD: Makefile,v 1.14 2003/09/15 14:49:44 jmmv Exp $
#

DISTNAME=	buildtool-0.14
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=buildtool/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://buildtool.sourceforge.net/
COMMENT=	Portable build infrastructure

USE_BUILDLINK2=	yes
HAS_CONFIGURE=	yes

PKG_SYSCONFSUBDIR=	buildtool

CONFIGURE_ARGS=		-p ${LOCALBASE}
CONFIGURE_ARGS+=	-c ${PKG_SYSCONFDIR}
CONFIGURE_ENV+=		SH="${SH}"

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD-1.5*)
DEPENDS+=		m4>=1.4nb1:../../devel/m4
M4=			"${GNU_PROGRAM_PREFIX}m4"
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/buildtool-0/pkgflags

.include "../../mk/bsd.pkg.mk"
