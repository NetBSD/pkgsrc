# $NetBSD: Makefile,v 1.2 2011/10/09 10:02:47 cheusov Exp $
#

DISTNAME=	pipestatus-0.6.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pipestatus/}

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/pipestatus/
COMMENT=	UNIX/POSIX shell helper for running pipes safely
LICENSE=	public-domain

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=		yes
NO_BUILD=		yes

INSTALLATION_DIRS+=	bin share/doc/pipestatus
DOCS=			README NEWS

TEST_TARGET=		test
MAKE_FLAGS+=		SH=${SH:Q}

do-install:
	${INSTALL_DATA} ${WRKSRC}/pipestatus ${DESTDIR}${PREFIX}/bin/
.for doc in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DESTDIR}${PREFIX}/share/doc/pipestatus/
.endfor

.include "../../mk/bsd.pkg.mk"
