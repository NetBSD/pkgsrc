# $NetBSD: Makefile,v 1.25 2015/05/12 15:45:21 bsiegert Exp $
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

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
