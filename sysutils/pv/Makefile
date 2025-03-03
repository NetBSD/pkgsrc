# $NetBSD: Makefile,v 1.34 2025/03/03 21:34:21 schmonz Exp $

DISTNAME=	pv-1.9.31
CATEGORIES=	sysutils
MASTER_SITES=	https://www.ivarch.com/programs/sources/
MASTER_SITES+=	${MASTER_SITE_SOURCEFORGE:=pipeviewer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.ivarch.com/programs/pv.shtml
COMMENT=	Monitor the progress of data through a pipeline
LICENSE=	artistic-2.0

USE_TOOLS+=		gmake msgfmt
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

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

PV_SHARE_FILES=		ACKNOWLEDGEMENTS.md COPYING DEVELOPERS.md INSTALL \
			NEWS.md benchmark.sh

post-install:
.for i in ${PV_SHARE_FILES}
	${INSTALL_DATA} ${WRKSRC}/docs/${i} ${DESTDIR}${DOCDIR}
.endfor

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
