# $NetBSD: Makefile,v 1.27 2019/06/10 16:55:02 nia Exp $
#

DISTNAME=		pv-1.6.6
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

# configure test only checks for open64()
CFLAGS.SunOS+=		-DENABLE_LARGEFILE=1

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
