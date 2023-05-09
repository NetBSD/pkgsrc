# $NetBSD: Makefile,v 1.29 2023/05/09 21:26:18 dholland Exp $
#

DISTNAME=		pv-1.6.20
CATEGORIES=		sysutils
MASTER_SITES=		https://www.ivarch.com/programs/sources/
MASTER_SITES+=		${MASTER_SITE_SOURCEFORGE:=pipeviewer/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.ivarch.com/programs/pv.shtml
COMMENT=		Monitor the progress of data through a pipeline
LICENSE=		artistic-2.0

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake msgfmt
USE_PKGLOCALEDIR=	yes

REPLACE_LOCALEDIR_PATTERNS+=	vars.mk

DOCDIR=			${PREFIX}/share/doc/pv
INSTALLATION_DIRS=	${DOCDIR}

.include "../../mk/bsd.prefs.mk"

# configure test only checks for open64()
CFLAGS.SunOS+=		-DENABLE_LARGEFILE=1

# configure test produces uncompilable results
.if ${OPSYS} == "Darwin" && ${MACHINE_ARCH} == "aarch64"
CONFIGURE_ENV+=		ac_cv_func_stat64=no
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
