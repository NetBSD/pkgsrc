# $NetBSD: Makefile,v 1.5 1998/04/15 10:38:21 agc Exp $
#

DISTNAME=	readline-2.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	packages@netbsd.org

BUILD_DEPENDS=	${PREFIX}/bin/install-info:${PORTSDIR}/devel/gtexinfo
RUN_DEPENDS=    ${PREFIX}/bin/install-info:${PORTSDIR}/devel/gtexinfo

GNU_CONFIGURE=	yes

MAN3=		readline.3

SCRIPTS_ENV+=	PLIST_SRC="${PLIST_SRC}"

do-build:
	(cd ${WRKSRC}; make LIB=readline)
	(cd ${WRKSRC}; make LIB=history)

post-install:
	@${LDCONFIG} || ${TRUE}

.include "../../mk/bsd.pkg.mk"
