# $NetBSD: Makefile,v 1.26 2015/06/22 22:29:53 jperkin Exp $
#

DISTNAME=		pv-1.6.0
CATEGORIES=		sysutils
MASTER_SITES=		http://www.ivarch.com/programs/sources/
MASTER_SITES+=		${MASTER_SITE_SOURCEFORGE:=pipeviewer/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.ivarch.com/programs/pv.shtml
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
